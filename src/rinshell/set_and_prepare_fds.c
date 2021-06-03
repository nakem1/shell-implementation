/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_prepare_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:37:04 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:52:54 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	prog_set_fd(int i, int **fd, int count, t_prog *prog)
{
	if (prog->redirect_fd > 0)
		dup2(prog->redirect_fd, STDOUT_FILENO);
	else if (i != count - 1 && i != -1)
		dup2(fd[i][1], STDOUT_FILENO);
	if (prog->input_fd > 0)
		dup2(prog->input_fd, STDIN_FILENO);
	else if (i != 0 && i != -1)
		dup2(fd[i - 1][0], STDIN_FILENO);
	if (i != -1)
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
