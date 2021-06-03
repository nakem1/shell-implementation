/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shielding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:59:10 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 19:06:29 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		handle_backslash(t_parse *parse)
{
	parse->replace_str[parse->i_str][0] = '\0';
	if (parse->str[parse->i_str + 1] == '\0')
		parse->error_flag = 1;
	parse->i_str += 2;
}

void		handle_quotes(t_parse *parse)
{
	int *i;

	i = &(parse->i_str);
	parse->replace_str[*i][0] = '\0';
	*i += 1;
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] != '\"')
	{
		if (parse->replace_str[*i][0] == '$')
			handle_env(parse);
		else if (parse->replace_str[*i][0] == '\\')
			handle_backslash(parse);
		else
			*i += 1;
	}
	if (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] == '\"')
	{
		parse->replace_str[*i][0] = '\0';
		*i += 1;
	}
	else
		parse->error_flag = 1;
}

void		handle_apostrophe(t_parse *parse)
{
	int *i;

	i = &(parse->i_str);
	parse->replace_str[*i][0] = '\0';
	*i += 1;
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] != '\'')
		*i += 1;
	if (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] == '\'')
	{
		parse->replace_str[*i][0] = '\0';
		*i += 1;
	}
	else
		parse->error_flag = 1;
}

void		handle_shielding(t_parse *parse)
{
	int *i;

	i = &(parse->i_str);
	if (parse->str[*i] == '\\')
		handle_backslash(parse);
	else if (parse->str[*i] == '\"')
		handle_quotes(parse);
	else if (parse->str[*i] == '\'')
		handle_apostrophe(parse);
}
