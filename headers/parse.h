/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:03:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/27 08:17:30 by lmurray          ###   ########.fr       */
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
	int				error_flag;
	// int				count_quotes;
}					t_parse;

void		line_division(t_parse *parse);
t_shell		*parse(char *str, char **env);
void		skip_spaces(t_parse *parse, int *i);
int			skip_alpha(t_parse *parse, int *i);
t_prog		*set_output_str(t_parse *parse);
int			word_counter(t_parse *parse);
void		handle_env(t_parse *parse);
void		handle_shielding(t_parse *parse);
void		free_array2d(char **arr);
void		free_shell(t_shell **shell);

#endif
