/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:39:29 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:40:32 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPELINE 1
#include "minishell.h"

void	handle_pipeline(t_list *list, char ***envp,
int count_progs, int *exit_status)
{
	int		i;
	int		**fd;
	pid_t	pid;
	t_prog	*prog;

	i = -1;
	fd = init_fd_array(count_progs - 1);
	connect_pipes(fd, count_progs);
	while (++i < count_progs)
	{
		prog = list->content;
		pid = fork();
		if (pid == 0)
		{
			set_signals(1);
			prog_set_fd(i, fd, count_progs, prog);
			handle_one_prog(prog, envp, PIPELINE, exit_status);
		}
		list = list->next;
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

void	one_prog_redirect(t_prog *prog, char ***envp, int *exit_status)
{
	pid_t	pid;

	if (ft_strcmp(prog->prog_args[0], "export") == 0 && prog->count_args != 1)
		export(prog->count_args, prog->prog_args, envp, exit_status);
	else if (ft_strcmp(prog->prog_args[0], "cd") == 0)
		cd(prog->count_args, prog->prog_args[1], envp, exit_status);
	if (*exit_status != 1)
	{
		pid = fork();
		if (pid == 0)
		{
			prog_set_fd(-1, NULL, 0, prog);
			handle_one_prog(prog, envp, 1, exit_status);
		}
		wait(exit_status);
	}
}
