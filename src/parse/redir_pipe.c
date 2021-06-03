/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 08:11:09 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 21:37:37 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		check_eolfile(t_parse *parse, int start_redir)
{
	while (start_redir < parse->i_str)
	{
		if (parse->replace_str[start_redir][0] != -1)
		{
			parse->error_flag = 1;
			return ;
		}
		start_redir++;
	}
}

void		copy_env_toredirect(t_parse *parse, int *i, char *file, int *j)
{
	int k;

	k = 0;
	while (parse->replace_str[*i][k] != '\0')
	{
		file[*j + k] = parse->replace_str[*i][k];
		k++;
	}
	*j += k;
	*i += 1;
}

/*
**		while (start_redir < parse->i_str &&
**				parse->replace_str[start_redir][0] != -1)
**		{
**			if (parse->replace_str[start_redir][0] == '\0')
**				start_redir++;
**			else if (parse->replace_str[start_redir][0] != '\0' &&
**					parse->replace_str[start_redir][1] != '\0')
**				copy_env_toredirect(parse, &start_redir, prog->redirect_file,
**						&i_redir);
**			else
**			{
**				prog->redirect_file[i_redir++] =
**						parse->replace_str[start_redir++][0];
**				parse->replace_str[start_redir - 1][0] = '\0';
**			}
**		}
*/

void		set_redirect_file(t_parse *parse, t_prog *prog, int start_redir)
{
	int count;
	int i_redir;

	i_redir = 0;
	skip_spaces(parse, &start_redir);
	if (!(count = count_letters_inword(parse, start_redir)))
	{
		parse->error_flag = 1;
		return ;
	}
	prog->redirect_file = (char *)malloc(sizeof(char) * (count + 1));
	prog->redirect_file[count] = '\0';
	set_redirect_file_utils(parse, prog, &start_redir, &i_redir);
}

void		handle_redirect(t_parse *parse, t_prog *prog)
{
	int start_redir;

	if (parse->replace_str[parse->i_str] != NULL &&
			(parse->replace_str[parse->i_str][0] == '>' ||
			parse->replace_str[parse->i_str][0] == '<'))
	{
		if (parse->replace_str[parse->i_str + 1] == NULL)
		{
			parse->error_flag = 1;
			return ;
		}
		handle_redirect_utils(parse, prog);
		parse->replace_str[parse->i_str][0] = '\0';
		parse->i_str++;
		start_redir = parse->i_str;
		redirect_line_move(parse);
		set_redirect_file(parse, prog, start_redir);
		if (prog->flag_redirect == e_stdout_redirect || prog->flag_redirect \
				== e_append_redirect)
			prog->redirect_fd = open_redirect(parse, prog->flag_redirect, \
					prog->redirect_file);
		else
			prog->input_fd = open_redirect(parse, prog->flag_redirect, \
				prog->redirect_file);
	}
}

void		handle_semicolon_pipe(t_parse *parse, t_prog *prog)
{
	if (parse->replace_str[parse->i_str] == NULL)
		return ;
	else if (parse->replace_str[parse->i_str][0] == '|')
	{
		prog->flag_separator = e_pipe;
		parse->shell->count_progs++;
		parse->i_str++;
	}
	else if (parse->replace_str[parse->i_str][0] == ';')
	{
		prog->flag_separator = e_semicolon;
		parse->this_semicolon = 1;
		parse->i_str++;
	}
	else
		parse->error_flag = 1;
}
