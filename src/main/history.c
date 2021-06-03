/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:49:55 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:07:01 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			move_history(t_history *history, int direction)
{
	int size;

	size = ft_list_size(history->list);
	if (size == 0)
		return (1);
	if (direction == -1)
	{
		if (history->i <= -1)
			return (0);
		else
			history->i -= 1;
	}
	else
	{
		if (history->i >= size - 1)
			return (0);
		else
			history->i += 1;
	}
	return (2);
}

void		previous_command(t_history *history)
{
	int		flag;
	t_list	*list_tmp;
	char	*str;

	flag = move_history(history, 1);
	if (flag == 1 || flag == 0)
		return ;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("cd", 0), 1, ft_putchar);
	if (flag == 2)
	{
		list_tmp = ft_list_at(history->list, history->i);
		str = (char *)list_tmp->content;
		ft_putstr_fd(str, 1);
		if (history->tmp_str != NULL)
			free(history->tmp_str);
		history->tmp_str = ft_strdup(str);
	}
}

void		next_command(t_history *history)
{
	int		flag;
	t_list	*list_tmp;
	char	*str;

	flag = move_history(history, -1);
	if (flag == 1)
		return ;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("cd", 0), 1, ft_putchar);
	if (history->i == -1)
	{
		ft_putstr_fd(history->tmp_str2, 1);
		return ;
	}
	if (flag == 2)
	{
		list_tmp = ft_list_at(history->list, history->i);
		str = (char *)list_tmp->content;
		ft_putstr_fd(str, 1);
		if (history->tmp_str != NULL)
			free(history->tmp_str);
		history->tmp_str = ft_strdup(str);
	}
}

int			press_enter(t_history *history, t_termcap *termcap)
{
	char	*dup;
	int		return_flag;

	return_flag = 0;
	if (history->tmp_str != NULL)
	{
		tcgetattr(0, &(termcap->term));
		termcap->term.c_lflag |= (ECHO);
		termcap->term.c_lflag |= (ICANON);
		termcap->term.c_lflag |= (ISIG);
		tcsetattr(0, TCSANOW, &(termcap->term));
		dup = ft_strdup(history->tmp_str);
		ft_list_push_front(&history->list, dup);
		free(termcap->name_term);
		if (history->tmp_str2 != NULL)
			free(history->tmp_str2);
	}
	else
		return_flag = 1;
	write(1, "\n", 1);
	return (return_flag);
}

void		handle_command(char *str, t_history *history)
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
