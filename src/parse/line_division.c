/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_division.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 01:46:45 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/09 17:25:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			line_move(t_parse *parse)
{
	int *i;

	i = &(parse->i_str);
	while (parse->str[*i] != '\0' && parse->str[*i] != '|'
			&& parse->str[*i] != ';' && parse->error_flag == 0)
	{
		if (parse->str[*i] == '\"' || parse->str[*i] == '\''
				|| parse->str[*i] == '\\')
			handle_shielding(parse);
		else if (parse->str[*i] == ' ')
		{
			parse->replace_str[*i][0] = -1;
			parse->i_str++;
		}
		else if (parse->str[parse->i_str] == '$')
			handle_env(parse);
		else if (parse->str[*i] != '>' && parse->str[*i] != '<')
			handle_redirect(parse, )
		else
			parse->i_str++;
	}
}

/*
** 		Function:			char		*get_need_env()
**
** 		return:				required env vars
*/

char			*get_need_env(t_parse *parse, int j)
{
	int		i;
	int		count;
	char	*str_env;

	i = 0;
	str_env = (char *)malloc(sizeof(char) * ((parse->i_str - j) + 2));
	while (j + i < parse->i_str)
	{
		str_env[i] = parse->str[j + i];
		i++;
	}
	str_env[i] = '=';
	str_env[i + 1] = '\0';
	i = 0;
	while (parse->env[i] != NULL)
	{
		if (!ft_strncmp(str_env, parse->env[i], ft_strlen(str_env)))
		{
			count = ft_strlen(str_env);
			free(str_env);
			str_env = ft_strdup(&(parse->env[i][count]));
			return (str_env);
		}
		i++;
	}
	return (NULL);
}
// исправить этот бред сумасшедшего
void			reset_replace_str(t_parse *parse, int j, char *target_env)
{
	if (target_env != NULL)
	{
		free(parse->replace_str[j]);
		parse->replace_str[j] = target_env;
	}
	else
		parse->replace_str[j][0] = '\0';
	while (++j < parse->i_str)
		parse->replace_str[j][0] = '\0';
}

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

	i = &(parse->i_str);
	j = *i;
	count = 0;
	*i += 1;
	while (ft_isalpha(parse->str[*i]) || ft_isdigit(parse->str[*i]) || \
			parse->str[*i] == '_')
	{
		count++;
		*i += 1;
	}
	target_env = get_need_env(parse, j + 1);
	reset_replace_str(parse, j, target_env);
}

void			line_division(t_parse *parse)
{
	t_prog	*prog;

	parse->number_args = 0;
	parse->start_command = parse->i_str;
	line_move(parse);
	if (parse->error_flag != 0)
		return ;
	if (!(prog = set_output_str(parse)))
		return ;
	handle_redirect(parse, prog);
	handle_semicolon_pipe(parse, prog); // увеличить каунт прог и расставить флаги
}
