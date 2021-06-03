/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:24:15 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:06:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "main.h"
#include "minishell.h"

void		ctrl_c(t_history *history, t_termcap *termcap, char **envp)
{
	(void)*termcap;
	write(1, "\n", 1);
	if (history->tmp_str != NULL)
	{
		free(history->tmp_str);
		history->tmp_str = NULL;
	}
	prompt(envp);
}

int			main(int argc, char **argv, char **env)
{
	t_history		history;
	char			**envp;

	(void)argc;
	(void)argv;
	init_envp(&envp, env);
	history.list = NULL;
	while (1)
	{
		prompt(envp);
		termcaps(&history, envp);
		if (history.errors != 0 && history.errors != -1)
			handle_errors(history.errors);
		else if (history.errors == -1)
		{
			write(1, "exit\n", 5);
			return (0);
		}
		handler(history.tmp_str, &envp);
		free(history.tmp_str);
		history.tmp_str = NULL;
	}
}
