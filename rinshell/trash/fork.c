/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:33:31 by frariel           #+#    #+#             */
/*   Updated: 2021/04/13 16:46:06 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	// char *argv[] = {"ls", "-l", "-h", "-a", NULL};

	pid_t	child_pid;
	pid_t	wait_res;
	int		stat_loc;

	child_pid = fork();
	child_pid = fork();
	child_pid = fork();

	// execve(argv[0], argv, NULL);
	if (child_pid == 0)
	{
		// sleep(1);
		// child_pid = fork();
		printf("### Child ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);
	}
	else
	{
		wait_res = waitpid(child_pid, &stat_loc, WUNTRACED);
		printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);
	}
	return (0);
}
