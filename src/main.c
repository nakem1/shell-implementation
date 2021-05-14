/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:24:15 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/13 23:39:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "main.h"

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	termcap_init(t_termcap *termcap)
{
	tcgetattr(0, &(termcap->term));
	termcap->term.c_lflag &= ~(ECHO);
	termcap->term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &(termcap->term));
	tgetent(0, termcap->name_term);
	tputs(save_cursor, 1, ft_putchar);
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


int		main(int argc, char **argv, char const **envp)
{
	char			str[2000];
	int				l;
	t_termcap		termcap;
	
	(void)argc;
	(void)argv;
	(void)envp;
	termcap_init(&termcap);
	while (1)
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (!strcmp(str, "\e[A"))
			previous_command();
		else if (!strcmp(str, "\e[B"))
			next_command();
		else if (!strcmp(str, "\177"))// && !strcmp(str, "\177"))
			delete_symbol();
		else if (!ft_strcmp(str, "\4"))
			return (0);
		else
			write(1, str, l);
	} 
		// write(1, str, l);
	write(1, "\n", l);
	return (0);
}

