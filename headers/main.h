/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:20:28 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/13 23:24:30 by lmurray          ###   ########.fr       */
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

#endif
