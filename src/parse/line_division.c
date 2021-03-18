/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_division.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 01:46:45 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/18 10:34:29 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


/*
** 		Function:			void		handle_env()
**
** 		Description:		fn replace enviromental vars
*/

void			handle_env(t_parse *parse)
{
	int		*i;
	int		j;
	int		count;
	char	*target_env;

	i = parse->i_str;
	j = *i;
	count = 0;
	*i++;
	while (ft_isalpha(parse->str[*i]) || ft_isdigit(parse->str[*i]) || \
			parse->str[*i] == '_')
	{
		count++;
		*i += 1;
	}
	target_env = get_need_env(parse, j);
	if (target_env != NULL)
	{
		free(parse->replace_str[j]);
		parse->replace_str[j] = target_env;
	}
	reset_replace_str(parse, j + 1);
}

void			line_division(t_parse *parse)
{
	int		*i;
	int		size_word;
	char	*str;

	size_word = 0;
	i = parse->i_str;
	while (parse->str[*i] != '\0' && parse->str[*i] != '|' && \
			parse->str[*i] != ';' && parse->str[*i] && parse->str[*i] != '>' &&
			parse->str[*i] != '<')
	{
		// if (parse->str[*i] == "\"" || parse->str[*i] == "\'" || \
		// 		parse->str[*i] == "\\")
		// 	handle_shielding(parse);
		if (parse->str[*i] == '$')
			handle_env(parse);
		parse->i_str++;
	}
	// if (parse->i_str == '\0')
	// 	parse->shell->count_progs++;
}
