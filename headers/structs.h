/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:56:47 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/30 02:07:32 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**		e_pipe(0) |
**		e_semicolon(1) ;
**		e_stdin_redirect(2) <
**		e_stdout_redirect(3) >
**		e_append_redirect(4) >>
*/

enum			e_settings
{
	e_pipe,
	e_semicolon,
	e_stdin_redirect,
	e_stdout_redirect,
	e_append_redirect,
};

/*
** 		prog_name - name of executable program
**		prog_args - arguments of programm
**		flag_separator - type of communication between commands
**		flag_redirect - type of redirects
**		redirect_file - file required for redirection
*/

typedef struct		s_prog
{
	char			*prog_name;
	char			**prog_args;
	int				count_args;
	int				flag_separator;
	int				flag_redirect;
	char			*redirect_file;
}					t_prog;

typedef struct		s_shell
{
	t_list			*progs_list;
	int				count_progs;
}					t_shell;

#endif
