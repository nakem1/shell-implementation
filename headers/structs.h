/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:56:47 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/24 17:43:51 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "libft.h"

/*
**		e_pipe(0) |
**		e_semicolon ;
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

# define NONE_FD -300

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
	int				flag_separator; // if -1 -> 1 prog
	int				flag_redirect;
	char			*redirect_file;
	int				redirect_fd;
}					t_prog;

typedef struct		s_shell
{
	t_list			*progs_list;
	int				count_progs;
}					t_shell;

#endif
