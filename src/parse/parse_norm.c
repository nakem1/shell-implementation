/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:38:59 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 21:42:05 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			norm_check_empty_token(t_norm *norm, char *str, char delim)
{
	norm->j = norm->i;
	if (norm->j == 0 || norm->j == norm->size_list - 1)
		return (1);
	norm->j--;
	while (str[norm->j] != delim && norm->j > -1)
	{
		if (str[norm->j] != ' ')
			norm->flag = 1;
		norm->j--;
	}
	if (norm->flag == 0)
		return (1);
	norm->j = norm->i;
	norm->flag = 0;
	norm->j++;
	while (str[norm->j] != delim && norm->j < norm->size_list)
	{
		if (str[norm->j] != ' ')
			norm->flag = 1;
		norm->j++;
	}
	if (norm->flag == 0)
		return (1);
	norm->i = ft_strindx(str, delim, norm->i + 1);
	return (0);
}

int			check_empty_token(char *str, char delim)
{
	t_norm	norm;

	norm.i = 0;
	if ((norm.i = ft_strindx(str, delim, norm.i)) == -1)
		return (0);
	norm.size_list = ft_strlen(str);
	norm.flag = 0;
	while (norm.i != -1)
	{
		if (norm_check_empty_token(&norm, str, delim) == 1)
			return (1);
	}
	if (norm.flag == 0)
		return (1);
	else
		return (0);
}

void		norm_parse(t_parse *parse, t_shell **shell, int *global)
{
	*shell = parse->shell;
	*global = parse->i_str;
	free_array2d(parse->replace_str);
	free(parse);
}

void		init_struct_norm(t_parse *parse, char *str, char **env, int *global)
{
	parse->shell->count_progs = 1;
	parse->shell->progs_list = NULL;
	parse->str = str;
	parse->i_str = *global;
	parse->start_command = 0;
	parse->number_args = 0;
	parse->error_flag = 0;
	parse->this_semicolon = 0;
	parse->env = env;
}
