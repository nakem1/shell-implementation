/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:12:30 by frariel           #+#    #+#             */
/*   Updated: 2021/06/02 21:07:01 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPELINE 1

#include "minishell.h"

int		print_fn(t_shell *shell, char ***envp)
{
	t_list	*list;
	t_prog	*prog;
	int		exit_status;

	list = shell->progs_list;
	exit_status = 0;
	prog = list->content;
	set_signals(0);
	if (shell->count_progs == 1 && prog->prog_args != NULL)
	{
		add_underscore(prog, envp, 1);
		handle_one_prog(prog, envp, 0, &exit_status);
	}
	else if (prog->prog_args != NULL)
	{
		add_underscore(prog, envp, 0);
		handle_pipeline(list, envp, shell->count_progs, &exit_status);
	}
	set_exit_status(exit_status, envp);
	return (0);
}

void	set_signals(int flag)
{
	if (flag == 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	set_exit_status(int exit_status, char ***envp)
{
	char	**command;

	command = NULL;
	if (exit_status == 0)
	{
		command = ft_split("export ?=0", ' ');
		export(2, command, envp);
		clear_env_array(command);
	}
	else
		signal_exit(envp, exit_status);
}

void	signal_exit(char ***envp, int exit_status)
{
	char	*status;
	char	**command;
	char	*str;

	if (exit_status == 2 || exit_status == 3)
		write(1, "\n", 1);
	if (exit_status == 256)
		exit_status = 127;
	if (exit_status == 2)
		exit_status = 130;
	if (exit_status == 3)
		exit_status = 131;
	status = ft_itoa(exit_status);
	str = ft_strjoin("export ?=", status);
	command = ft_split(str, ' ');
	free(str);
	free(status);
	export(2, command, envp);
	clear_env_array(command);
}

void	connect_pipes(int **fd, int count)
{
	int		i;

	i = 0;
	while (i < count - 1)
	{
		pipe(fd[i]);
		i++;
	}
	i = 0;
}

int		**init_fd_array(int pipes)
{
	int	i;
	int	**fd;

	fd = NULL;
	i = 0;
	if (pipes != 0)
	{
		fd = (int**)malloc(sizeof(int*) * pipes);
		if (!fd)
			exit_and_error("memory allocation failed", "malloc");
	}
	while (i < pipes)
	{
		fd[i] = (int*)malloc(sizeof(int) * 2);
		if (!fd[i])
			exit_and_error("memory allocation failed", "malloc");
		i++;
	}
	return (fd);
}



void	prog_set_fds(int i, int **fd, int count)
{
	int j;

	j = 0;
	if (i != -1)
	{
		if (i != count - 1)
			dup2(fd[i][1], STDOUT_FILENO);
		if (i != 0)
			dup2(fd[i - 1][0], STDIN_FILENO);
	}
	while (j < count - 1)
	{
		close(fd[j][0]);
		close(fd[j][1]);
		j++;
	}
}

void	prog_set_fd(int i, int **fd, int count, t_prog *prog)
{
	if (prog->redirect_fd > 0)
		dup2(prog->redirect_fd, STDOUT_FILENO);
	else if (i != count - 1)
		dup2(fd[i][1], STDOUT_FILENO);
	if (prog->input_fd > 0)
		dup2(prog->input_fd, STDIN_FILENO);
	else if (i != 0)
		dup2(fd[i - 1][0], STDIN_FILENO);
	close_fd(count, fd);
}

void	close_fd(int count, int **fd)
{
	int		j;

	j = 0;
	while (j < count - 1)
	{
		close(fd[j][0]);
		close(fd[j][1]);
		j++;
	}
}

void	clear_fd_array(int **fd, int pipes)
{
	int		i;

	i = 0;
	while (i < pipes)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	handle_pipeline(t_list *list, char ***envp,
	int count_progs, int *exit_status)
{
	int		i;
	int		**fd;
	pid_t	pid;
	t_prog	*prog;

	i = 0;
	fd = init_fd_array(count_progs - 1);
	connect_pipes(fd, count_progs);
	while (i < count_progs)
	{
		prog = list->content;
		pid = fork();
		if (pid == 0)
		{
			set_signals(1);
			prog_set_fd(i, fd, count_progs, prog);
			// prog_set_fds(i, fd, count_progs);
			handle_one_prog(prog, envp, PIPELINE, exit_status);
		}
		list = list->next;
		i++;
	}
	close_fd(count_progs, fd);
	clear_fd_array(fd, count_progs - 1);
	i = 0;
	while (i++ < count_progs)
		wait(exit_status);
}


void	handle_one_prog(t_prog *prog, char ***envp, int flag, int *exit_status)
{
	int	pid;

	if (check_built_in(prog->prog_args) == 1)
	{
		run_built_in(prog->count_args, prog->prog_args, envp, exit_status);
		if (flag == PIPELINE)
			exit(0);
	}
	else if (flag != PIPELINE)
	{
		pid = fork();
		if (pid == 0)
		{
			set_signals(1);
			run_binary(prog->prog_args, *envp);
		}
		wait(exit_status);
	}
	else
		run_binary(prog->prog_args, *envp);

}

void	run_binary(char **command, char **envp)
{
	if (check_slash(command[0]) == 0)
		run_path(command, envp);
	else
	{
		execve(command[0], command, envp);
		exit_and_error(strerror(errno), command[0]);
	}
}

int		check_slash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	exit_and_error(char *message, char *command)
{
	printf("minishell: %s: %s\n", command, message);
	exit(1);
}
