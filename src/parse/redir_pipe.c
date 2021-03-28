/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 08:11:09 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/28 09:42:31 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// void		handle_redirect(t_parse *parse, t_prog *prog, int flag)
// {
// 	int count;

// 	prog->flag = flag;
// 	parse->i_str++;
// 	if (flag == e_append_redirect)
// 		parse->i_str++;
// 	count = file_count(parse); // количество символов в файле редиректа
// 	prog->redirect_file = (char *)malloc(sizeof(char) * (count + 1));
// 	prog->redirect_file[count] = '\0';
// 	while (parse->str[parse->i_str] != '\0' && parse->str[parse->i_str] != '|'
// 			&& parse->str[parse->i_str] != ';')
// 	{

// 	}
// }

void		set_redirect_file(t_parse *parse, t_prog *prog, int start_redir)
{
	int count;

	skip_spaces(parse, &start_redir);
	count = get_size_file(parse, start_redir);
	if (count == 0)
	{
		parse->error_flag = 1;
		return ;
	}
	prog->redirect_file = (char *)malloc(sizeof(char) * (count + 1));
	prog->redirect_file[count] = '\0';
	while (parse->replace_str[start_redir] != NULL &&
			parse->replace_str[start_redir][0] != -1)
	{
		if (parse->replace_str[start_redir][0] == '\0')
			start_redir++;
		else if (parse->replace_str[start_redir][0] != '\0' &&
				parse->replace_str[start_redir][1] != '\0')
		//дописать вставку из replace_str
	}
}

void		handle_redirect(t_parse *parse, t_prog *prog)
{
	int start_redir;

	start_redir = parse->i_str;
	if (parse->replace_str[parse->i_str][0] != '>' &&
			parse->replace_str[parse->i_str][0] != '<')
		return ;
	else if (parse->replace_str[parse->i_str][0] == '<' &&
			parse->replace_str[parse->i_str + 1][0] != '<')
		prog->flag = e_stdin_redirect;
	else if (parse->replace_str[parse->i_str][0] == '>' &&
			parse->replace_str[parse->i_str + 1][0] != '>')
		prog->flag = e_stdout_redirect;
	else if (parse->replace_str[parse->i_str][0] == '>' &&
			parse->replace_str[parse->i_str + 1][0] == '>')
	{
		prog->flag = e_append_redirect;
		parse->i_str++;
	}
	parse->i_str++;
	line_move(parse);
	set_redirect_file(parse, prog, start_redir);
}

void		handle_semicolon_pipe(t_parse *parse, t_prog *prog)
{
	if (parse->replace_str[parse->i_str][0] == '|')
	{
		prog->flag = e_pipe;
		parse->shell->count_progs++;
		parse->i_str++;
	}
	else if (parse->replace_str[parse->i_str][0 == ';'])
	{
		prog->flag = e_semicolon;
		parse->shell->count_progs++;
		parse->i_str++;
	}
	// else if (parse->replace_str[parse->i_str][0] == '<' &&
	// 		parse->replace_str[parse->i_str + 1][0] != '<')
	// 	handle_redirect(parse, prog, e_stdin_redirect);
	// else if (parse->replace_str[parse->i_str][0] == '>' &&
	// 		parse->replace_str[parse->i_str + 1][0] != '>')
	// 	handle_redirect(parse, prog, e_stdout_redirect);
	// else if (parse->replace_str[parse->i_str][0] == '>' &&
	// 		parse->replace_str[parse->i_str + 1][0] == '>')
	// 	handle_redirect(parse, prog, e_append_redirect);
}
