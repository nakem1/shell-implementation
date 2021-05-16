/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:20:28 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/16 03:46:33 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <term.h>
# include <termios.h>
# include <libft.h>

typedef struct		s_termcap
{
	struct termios	term;
	char			*name_term;
}					t_termcap;

typedef struct		s_history
{
	t_list			*list;
	char			*tmp_str;
	int				i;
}					t_history;


#endif
