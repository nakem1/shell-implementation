/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:56:47 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/27 08:31:23 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum			e_settings
{
	e_pipe,
	e_stdin_redirect,
	e_stdout_redirect,
	e_append_redirect,
};

/*
** 		prog_name - name of executable program
**		prog_args - arguments of programm
**		flag - output redirection type: PIPE, STDIN_REDIRECT(<),
**		STDOUT_REDIRECT(>), APPEND_REDIRECT(>>)
**		redirect_file - file required for redirection
*/

typedef struct		s_prog
{
	char			*prog_name;
	char			**prog_args;
	int				count_args;
	int				flag;
	char			*redirect_file;
}					t_prog;

typedef struct		s_shell
{
	t_list			*progs_list;
	int				count_progs;
}					t_shell;

#endif
