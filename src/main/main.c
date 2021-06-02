/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:24:15 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/02 20:41:02 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "main.h"
#include "minishell.h"

int				g_indx = 0; // !

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_info(t_termcap *termcap, t_history *history)
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

int		move_history(t_history *history, int direction)
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

void	previous_command(t_history *history)
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

void	next_command(t_history *history)
{
	int		flag;
	t_list	*list_tmp;
	char	*str;

	flag = move_history(history, -1);
	if (flag == 1)
		return ;
	tputs(restore_cursor, 1, ft_putchar);
	// tputs(tigetstr("ed"), 1, ft_putchar);
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

void	delete_symbol(t_history *history)
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

int		press_enter(t_history *history, t_termcap *termcap)
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

void		print_user(char **env)
{
	int			i;
	char		*name;

	i = 0;
	name = "LOGNAME=";
	while (env[i] != NULL)
	{
		if (!ft_strncmp(name, env[i], 8))
		{
			ft_putstr_fd(&env[i][8], 2);
			break ;
		}
		i++;
	}
}

void		print_pwd(char **env)
{
	int			i;
	char		*name;

	i = 0;
	name = "PWD=";
	while (env[i] != NULL)
	{
		if (!ft_strncmp(name, env[i], 4))
		{
			ft_putstr_fd(&env[i][4], 2);
			break ;
		}
		i++;
	}
}

void		prompt(char **env)
{
	ft_putstr_fd ("\033[32m# \033[0m", 2);
	print_user(env);
	ft_putstr_fd(" in ", 2);
	print_pwd(env);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("$ ", 2);
}

void		ctrl_c(t_termcap *termcap, char **envp)
{
	// tcgetattr(0, &(termcap->term));
	// termcap->term.c_lflag |= (ECHO);
	// termcap->term.c_lflag |= (ICANON);
	// termcap->term.c_lflag |= (ISIG);
	// tcsetattr(0, TCSANOW, &(termcap->term));
	(void)*termcap;
	write(1, "\n", 1);
	prompt(envp);
}

int			check_empty_str(char *str)
{
	if (str == NULL)
		return (1);
	else if (ft_strlen(str) == 0)
		return (1);
	else
		return (0);
}

void		termcaps(t_history *history, char **envp)
{
	char			str[2000];
	int				l;
	t_termcap		termcap;

	init_info(&termcap, history);
	while (1)
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (!ft_strcmp(str, "\e[A"))
		{
			if (history->i == -1 && history->tmp_str != NULL)
				history->tmp_str2 = ft_strdup(history->tmp_str);
			previous_command(history);
		}
		else if (!ft_strcmp(str, "\e[B"))
			next_command(history);
		else if (!ft_strcmp(str, "\177"))// && !strcmp(str, "\177"))
			delete_symbol(history);
		else if (!ft_strcmp(str, "\n"))
		{
			// press_enter(history, &termcap);
			if (!press_enter(history, &termcap))
				break ;
			prompt(envp);
		}
		else if (!ft_strcmp(str, "\3"))
			ctrl_c(&termcap, envp);
		else if (!ft_strcmp(str, "\4") && check_empty_str(history->tmp_str))
		{
			history->errors = -1;
			break ;
		}
		else
			handle_command(str, history);
	}
}

int			main(int argc, char **argv, char **env)
{
	t_history		history;
	char			**envp;
	(void)argc;
	(void)argv;
	// (void)env;
	init_envp(&envp, env);
	history.list = NULL;
	while (1)
	{
		prompt(envp);
		termcaps(&history, envp);
		// if (g_indx == 1)
			// while(1);
		if (history.errors != 0 && history.errors != -1)
			handle_errors(history.errors);
		else if (history.errors == -1)
		{
			write(1, "exit\n", 5);
			return (0);
		}
		// write(1, history.tmp_str, ft_strlen(history.tmp_str));
		handler(history.tmp_str, &envp);
		free(history.tmp_str);
		history.tmp_str = NULL;
		g_indx++;
	}
}
// TODO trouble with lists
// TODO вторая стрелка. Сега при пустом энтере
// TODO стрелка вверх, энтер
