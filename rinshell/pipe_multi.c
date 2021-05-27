/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:12:30 by frariel           #+#    #+#             */
/*   Updated: 2021/05/27 16:39:59 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPELINE 1

#include "minishell.h"

int		print_fn(t_shell *shell, char ***envp)
{
	t_list	*list;
	t_prog	*prog;
	list = shell->progs_list;
	prog = list->content;
	if (shell->count_progs == 1)
		handle_one_prog(prog->count_args, prog->prog_args, envp, 0);
	else
		handle_pipeline(list, envp, shell->count_progs);
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

void	handle_pipeline(t_list *list, char ***envp, int count_progs)
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
			prog_set_fd(i, fd, count_progs, 0);
			handle_one_prog(prog->count_args, prog->prog_args, envp, PIPELINE);
			return ;
		}
		list = list->next;
		i++;
	}
	prog_set_fd(i, fd, count_progs, 1);
	i = 0;
	while (i++ < count_progs)
		wait(NULL);
}

void	handle_one_prog(int argc, char **command, char ***envp, int flag)
{
	int	pid;

	if (check_built_in(command) == 1)
	{
		run_built_in(argc, command, envp);
		if (flag == PIPELINE)
			exit (0);
	}
	else if (flag != PIPELINE)
	{
		pid = fork();
		if (pid == 0)
			run_binary(command, *envp);
		wait(NULL);
	}
	else
		run_binary(command, *envp);

}

void	run_binary(char **command, char **envp)
{
	if (check_slash(command[0]) == 0)
		run_path(command, envp);
	else
	{
		execve(command[0], command, envp);
		exit_and_error("No such file or directory", command[0]);
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
	exit(0);
}
