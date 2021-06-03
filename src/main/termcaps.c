/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:48:26 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:46:44 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		init_info(t_termcap *termcap, t_history *history)
{
	termcap->name_term = ft_strdup("xterm-256color");
	tcgetattr(0, &(termcap->term));
	termcap->term.c_lflag &= ~(ECHO);
	termcap->term.c_lflag &= ~(ICANON);
	termcap->term.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &(termcap->term));
	tgetent(0, termcap->name_term);
	tputs(save_cursor, 1, ft_putchar);
	history->tmp_str = NULL;
	history->tmp_str2 = NULL;
	history->i = -1;
	history->errors = 0;
}

void		delete_symbol(t_history *history)
{
	int		size_str;

	if (history->tmp_str)
	{
		size_str = ft_strlen(history->tmp_str);
		if (size_str)
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
			history->tmp_str[size_str - 1] = '\0';
		}
	}
}

int			check_empty_str(t_history *history)
{
	if (history->tmp_str == NULL)
	{
		history->errors = -1;
		return (1);
	}
	else if (ft_strlen(history->tmp_str) == 0)
	{
		history->errors = -1;
		return (1);
	}
	else
		return (0);
}

void		termcaps_utils(t_termcap *termcap, t_history *history)
{
	if (!ft_strcmp(termcap->str, "\e[A"))
	{
		if (history->i == -1 && history->tmp_str != NULL)
			history->tmp_str2 = ft_strdup(history->tmp_str);
		previous_command(history);
	}
	else if (!ft_strcmp(termcap->str, "\e[B"))
		next_command(history);
	else if (!ft_strcmp(termcap->str, "\177"))
		delete_symbol(history);
}

/*
**		if (!ft_strcmp(termcap.str, "\e[A"))
**		{
**			if (history->i == -1 && history->tmp_str != NULL)
**				history->tmp_str2 = ft_strdup(history->tmp_str);
**			previous_command(history);
**		}
**		else if (!ft_strcmp(termcap.str, "\e[B"))
**			next_command(history);
**		else if (!ft_strcmp(termcap.str, "\177"))
**			delete_symbol(history);
*/

void		termcaps(t_history *history, char ***envp)
{
	t_termcap		termcap;

	init_info(&termcap, history);
	while (1)
	{
		termcap.l = read(0, termcap.str, 100);
		termcap.str[termcap.l] = 0;
		if (!ft_strcmp(termcap.str, "\e[A") || !ft_strcmp(termcap.str, "\e[B") \
				|| !ft_strcmp(termcap.str, "\177"))
			termcaps_utils(&termcap, history);
		else if (!ft_strcmp(termcap.str, "\n"))
		{
			if (!press_enter(history, &termcap))
				break ;
			prompt(*envp);
		}
		else if (!ft_strcmp(termcap.str, "\3"))
			ctrl_c(history, &termcap, envp);
		else if (!ft_strcmp(termcap.str, "\4") && check_empty_str(history))
			break ;
		else
			handle_command(termcap.str, history);
	}
}
