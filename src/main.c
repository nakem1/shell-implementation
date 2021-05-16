/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:24:15 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/16 21:19:16 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "main.h"

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_info(t_termcap *termcap, t_history *history)
{
	tcgetattr(0, &(termcap->term));
	termcap->term.c_lflag &= ~(ECHO);
	termcap->term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &(termcap->term));
	tgetent(0, termcap->name_term);
	tputs(save_cursor, 1, ft_putchar);
	history->tmp_str = NULL;
	history->list = NULL;
	history->i = 0;
}

void	previous_command(void)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	write(1, "previous", 8);
}

void	next_command(void)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	write(1, "next", 4);
}

void	delete_symbol(void)
{
	tputs(cursor_left, 1, ft_putchar);
	tputs(tgetstr("dc", 0), 1, ft_putchar);
}

void	handle_command(char *str, t_history *history)
{
	char	*tmp;

	if (ft_strcmp(str, "\e[D") && ft_strcmp(str, "\e[C")
		&& ft_strcmp(str, "\034") && ft_strcmp(str, "\4"))
	{
		tmp = ft_strjoin(history->tmp_str, str);
		if (history->tmp_str != NULL)
			free(history->tmp_str);
		history->tmp_str = tmp;
		ft_putstr_fd(str, 1);
	}
}

char		press_enter(t_history *history, t_termcap *termcap)
{
	tcgetattr(0, &(termcap->term));
	termcap->term.c_lflag |= (ECHO);
	termcap->term.c_lflag |= (ICANON);
	termcap->term.c_lflag |= (ISIG);
	tcsetattr(0, TCSANOW, &(termcap->term));
	if (history->tmp_str != NULL)
		ft_list_push_front(&history->list, history->tmp_str);
	write(1, "\n", 1);
	{
		free(history->tmp_str);
		history->tmp_str = NULL;
	}
	return (history->)
}

char		*termcaps(t_history *history)
{
	char			str[2000];
	int				l;
	t_termcap		termcap;
	
	init_info(&termcap, &history);
	while (1)
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (!ft_strcmp(str, "\e[A"))
			previous_command();
		else if (!ft_strcmp(str, "\e[B"))
			next_command();
		else if (!ft_strcmp(str, "\177"))// && !strcmp(str, "\177"))
			delete_symbol();
		else if (!ft_strcmp(str, "\n"))
			return (press_enter(&history, &termcap))
		else if (!ft_strcmp(str, "\4"))
			return (0);
		else
		{
			handle_command(str, &history);
			// printf("%s\n", history.tmp_str);
		}
	} 
		// write(1, str, l);
	write(1, "\n", l);
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	t_history		history;
}
