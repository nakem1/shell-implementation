/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_division_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:30:06 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 19:28:20 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*
** 		Description:		the function counts the number of characters in the
**		additional array. If replace_str[i][0] == -1 than stop. Argument is over
*/

int			count_letters_inword(t_parse *parse, int i)
{
	int count;

	count = 0;
	while (parse->replace_str[i] != NULL && parse->replace_str[i][0] != -1 &&
			i < parse->i_str)
	{
		count += ft_strlen(parse->replace_str[i]);
		i++;
	}
	return (count);
}

void		copy_env_tostr(t_parse *parse, int i, char **prog_args, int *j)
{
	int k;

	k = 0;
	while (parse->replace_str[i][k] != '\0')
	{
		prog_args[parse->number_args][*j + k] = parse->replace_str[i][k];
		k++;
	}
	*j += k;
}

int			word_counter(t_parse *parse)
{
	int i;
	int count;

	i = parse->start_command;
	count = 0;
	while (i < parse->i_str)
	{
		skip_spaces(parse, &i);
		if (i < parse->i_str)
		{
			count++;
			if (skip_alpha(parse, &i))
				count--;
		}
	}
	return (count);
}

int			set_word(t_parse *parse, int *i, t_prog *prog)
{
	int			count;
	int			j;

	j = 0;
	if (!(count = count_letters_inword(parse, *i)))
		return (1);
	prog->prog_args[parse->number_args] = (char *)malloc(sizeof(char) *
			(count + 1));
	prog->prog_args[parse->number_args][count] = '\0';
	while (parse->replace_str[*i] != NULL && parse->replace_str[*i][0] != -1 &&
			*i < parse->i_str)
	{
		if (parse->replace_str[*i][0] != '\0' &&
				parse->replace_str[*i][1] != '\0')
			copy_env_tostr(parse, *i, prog->prog_args, &j);
		else
		{
			if (parse->replace_str[*i][0] != '\0')
				prog->prog_args[parse->number_args][j++] =
						parse->replace_str[*i][0];
		}
		*i += 1;
	}
	return (0);
}

void		set_output_str(t_parse *parse, t_prog *prog)
{
	int		i;

	i = parse->start_command;
	if (!(prog->count_args = word_counter(parse)))
		return ;
	prog->prog_args = (char **)malloc(sizeof(char *) * (prog->count_args + 1));
	prog->prog_args[prog->count_args] = NULL;
	while (i < parse->i_str)
	{
		skip_spaces(parse, &i);
		if (!set_word(parse, &i, prog))
			parse->number_args++;
		else
			i++;
	}
}
