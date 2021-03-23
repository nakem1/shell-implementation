/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:03:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/21 04:49:42 by lmurray          ###   ########.fr       */
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
	int				number_args;
	// int				count_quotes;
}					t_parse;

void		line_division(t_parse *parse);
t_shell		*parse(char *str, char **env);
void		skip_spaces(t_parse *parse, int *i);
void		skip_alpha(t_parse *parse, int *i);
void		set_output_str(t_parse *parse);
int			word_counter(t_parse *parse);

#endif
