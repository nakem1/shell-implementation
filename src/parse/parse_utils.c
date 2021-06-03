/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:37:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 19:30:02 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		skip_spaces(t_parse *parse, int *i)
{
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] == -1 &&
			*i < parse->i_str)
	{
		*i += 1;
	}
}

int			skip_alpha(t_parse *parse, int *i)
{
	int flag;

	flag = 1;
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] != -1 &&
			*i < parse->i_str)
	{
		if (parse->replace_str[*i][0] != '\0')
			flag = 0;
		*i += 1;
	}
	return (flag);
}

int			open_redirect(t_parse *parse, int type, char *redirect_file)
{
	int fd;

	fd = -1;
	if (parse->error_flag)
		return (-1);
	if (type == e_stdout_redirect)
	{
		fd = open(redirect_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			parse->error_flag = e_memory;
	}
	else if (type == e_stdin_redirect)
	{
		fd = open(redirect_file, O_RDONLY);
		if (fd == -1)
			parse->error_flag = e_file_not_found;
	}
	else if (type == e_append_redirect)
	{
		fd = open(redirect_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			parse->error_flag = e_memory;
	}
	return (fd);
}

void		redirect_line_move(t_parse *parse)
{
	int *i;

	i = &(parse->i_str);
	while (parse->str[*i] == ' ')
	{
		parse->replace_str[*i][0] = -1;
		*i += 1;
	}
	while (parse->str[*i] != '\0' && parse->str[*i] != '|'
			&& parse->str[*i] != ';' && parse->error_flag == 0 && \
			parse->str[*i] != ' ')
	{
		if (parse->str[*i] == '\"' || parse->str[*i] == '\''
				|| parse->str[*i] == '\\')
			handle_shielding(parse);
		else if (parse->str[parse->i_str] == '$')
			handle_env(parse);
		else
			parse->i_str++;
	}
}
