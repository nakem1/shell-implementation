/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:37:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/20 08:54:29 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		skip_spaces(t_parse *parse, int *i)
{
	while (parse->replace_str[*i][0] == -1 && parse->replace_str[*i][0] != '\0'
			&& *i < parse->i_str)
	{
		*i += 1;
	}
}

void		skip_alpha(t_parse *parse, int *i)
{
	int count;

	count = 0;
	while (parse->replace_str[*i][0] != -1 && *i < parse->i_str &&
			parse->replace_str[*i][0] != '\0')
	{
		*i += 1;
		count++;
	}
	return (count);
}
