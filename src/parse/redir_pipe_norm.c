/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipe_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:35:49 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 21:42:32 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		handle_redirect_utils(t_parse *parse, t_prog *prog)
{
	if (parse->replace_str[parse->i_str][0] == '<' &&
			parse->replace_str[parse->i_str + 1][0] != '<')
		prog->flag_redirect = e_stdin_redirect;
	else if (parse->replace_str[parse->i_str][0] == '>' &&
			parse->replace_str[parse->i_str + 1][0] != '>')
		prog->flag_redirect = e_stdout_redirect;
	else if (parse->replace_str[parse->i_str][0] == '>' &&
			parse->replace_str[parse->i_str + 1][0] == '>')
	{
		prog->flag_redirect = e_append_redirect;
		parse->replace_str[parse->i_str][0] = '\0';
		parse->i_str++;
	}
	if (prog->redirect_file != NULL)
	{
		free(prog->redirect_file);
		prog->redirect_file = NULL;
	}
}

void		set_redirect_file_utils(t_parse *parse, t_prog *prog, \
		int *start_redir, int *i_redir)
{
	while (*start_redir < parse->i_str &&
				parse->replace_str[*start_redir][0] != -1)
	{
		if (parse->replace_str[*start_redir][0] == '\0')
			*start_redir += 1;
		else if (parse->replace_str[*start_redir][0] != '\0' &&
				parse->replace_str[*start_redir][1] != '\0')
			copy_env_toredirect(parse, start_redir, prog->redirect_file,
					i_redir);
		else
		{
			prog->redirect_file[*i_redir] =
					parse->replace_str[*start_redir][0];
			*i_redir += 1;
			*start_redir += 1;
			parse->replace_str[*start_redir - 1][0] = '\0';
		}
	}
}
