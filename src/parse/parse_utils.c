/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:37:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/23 02:28:49 by lmurray          ###   ########.fr       */
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

void		skip_alpha(t_parse *parse, int *i)
{
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] != -1 &&
			*i < parse->i_str)
	{
		*i += 1;
	}
}
