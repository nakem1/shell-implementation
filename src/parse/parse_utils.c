/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:37:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/09 16:50:43 by lmurray          ###   ########.fr       */
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
	else if (type == e_stdout_redirect)
	{
		fd = open(redirect_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			parse->error_flag = e_memory;
	}
	else
		printf("something wrong with redirect");
	return (fd);
}

void		handle_errors(int flag_error)
{
	if (flag_error == 1)
		printf("\x1b[31mSYNTAX ERROR. PLS man ne nado dushit\x1b[0m\n");
	else if (flag_error == e_memory)
		printf("\x1b[37;43mMEMORY ERROR. Not enough memory. Free up memory \
				with a script\x1b[0m\n");
	else if (flag_error == e_file_not_found)
		printf("\x1b[4;35mNO SUCH FILE(((\x1b[0m\n");
}
