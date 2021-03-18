/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:03:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/18 07:48:51 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "structs.h"

typedef struct		s_parse
{
	t_shell			*shell;
	char			*str;
	char			**replace_str;
	char			**env;
	int				i_str;
	// int				count_quotes;
}					t_parse;

void		line_division(t_parse *parse);
t_shell		*parse(char *str);

#endif
