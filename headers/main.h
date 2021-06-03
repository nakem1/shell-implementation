/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:20:28 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/04 00:23:59 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <term.h>
# include <termios.h>
# include "../src/libft/libft.h"
# include "errors.h"

typedef struct		s_termcap
{
	char			str[2000];
	int				l;
	struct termios	term;
	char			*name_term;
}					t_termcap;

typedef struct		s_history
{
	t_list			*list;
	char			*tmp_str;
	char			*tmp_str2;
	int				i;
	int				errors;
}					t_history;

void				handler(char *str, char ***env);
void				termcaps(t_history *history, char ***envp);
void				prompt(char **env);
int					press_enter(t_history *history, t_termcap *termcap);
void				next_command(t_history *history);
void				previous_command(t_history *history);
void				ctrl_c(t_history *history, t_termcap *termcap,
						char ***envp);
void				handle_command(char *str, t_history *history);

#endif
