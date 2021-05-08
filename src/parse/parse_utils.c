/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:37:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/08 01:58:31 by lmurray          ###   ########.fr       */
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
