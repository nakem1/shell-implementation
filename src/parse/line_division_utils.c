/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_division_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:30:06 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/20 09:38:49 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// void		allocate_words(t_parse *parse)
// {
// 	parse->shell->
// }

int			word_counter(t_parse *parse)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < parse->i_str)
	{
		skip_spaces(parse, &i);
		if (i < parse->i_str)
			count++;
		skip_alpha(parse, &i);
	}
	return (count);
}
// эта функция вызывается в цикле. Она запихивает нный аргумент из replace_str 
// в выходной массив
void		set_word(t_parse *parse, int *i, t_prog *prog, int number_word)
{
	int			count;
	static int	j;

	count = count_letters_inword(parse, i);
	prog->prog_args[number_word] = (char *)malloc(sizeof(char) * (count + 1));
	prog->prog_args[number_word][count] = '\0';
	while (parse->replace_str[*i][0] != -1 && *i < parse->i_str &&
			parse->replace_str[*i][0] != '\0')
	{
		if (parse->replace_str[*i][1] != '\0')
			copy_env_tostr(parse, i, prog, number_word);
		else
			prog->prog_args[number_word][j] = 
	}
}

void		set_output_str(t_parse *parse)
{
	int		i;
	int		number_word;
	int		count_words;
	t_prog	*prog;

	i = 0;
	number_word = 0;
	count_words = 0;
	count_words = word_counter(parse);
	prog = ft_list_last_content(parse->shell->progs_list);
	prog->count_args = count_words;
	prog->prog_args = (char **)malloc(sizeof(char *));
	allocate_words(parse); // аллокация памяти под каждое слово
	while (i < parse->i_str)
	{
		skip_spaces(parse, &i);
		set_word(parse, &i, prog, number_word);
		number_word++;
	}
}
