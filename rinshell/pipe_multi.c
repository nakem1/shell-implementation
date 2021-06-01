/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:12:30 by frariel           #+#    #+#             */
/*   Updated: 2021/06/01 16:59:30 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPELINE 1

#include "minishell.h"

int		print_fn(t_shell *shell, char ***envp)
{
	t_list	*list;
	t_prog	*prog;
	int		exit_status;

	signal(SIGINT, SIG_IGN);
	list = shell->progs_list;
	exit_status = 0;
	prog = list->content;
	if (shell->count_progs == 1 && prog->prog_args != NULL)
	{
		// if (prog->flag_redirect ==
		add_underscore(prog, envp, 1);
		handle_one_prog(prog, envp, 0, &exit_status);
	}
	else
	{
		handle_pipeline(list, envp, shell->count_progs, &exit_status);
		add_underscore(prog, envp, 1);
	}
	if (WIFEXITED(exit_status))
	{
		int es = WEXITSTATUS(exit_status);
		printf("Exit status was %d\n", es);
	}
	return (0);
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
			exit (1);
	}
	while (i < pipes)
	{
		fd[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	return (fd);
}

void	prog_set_fd(int i, int **fd, int count, int flag)
{
	int j;

	j = 0;
	if (flag == 0)
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
			signal(SIGINT, SIG_DFL);
			prog_set_fd(i, fd, count_progs, 0);
			handle_one_prog(prog, envp, PIPELINE, exit_status);
			return ;
		}
		list = list->next;
		i++;
	}
	prog_set_fd(i, fd, count_progs, 1);
	i = 0;
	while (i++ < count_progs)
		wait(exit_status);
}

void	handle_one_prog(t_prog *prog, char ***envp, int flag, int *exit_status)
{
	int	pid;

	if (check_built_in(prog->prog_args) == 1)
	{
		run_built_in(prog->count_args, prog->prog_args, envp);
		if (flag == PIPELINE)
			exit(0);
	}
	else if (flag != PIPELINE)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
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

int exit_and_error(char *message, char *command)
{
	printf("minishell: %s: %s\n", command, message);
	exit(1);
}
