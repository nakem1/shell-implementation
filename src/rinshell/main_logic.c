/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:12:30 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:44:34 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (prog->redirect_fd > 0)
			one_prog_redirect(prog, envp, &exit_status);
		else
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
