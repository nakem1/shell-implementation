/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:24:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/28 04:08:27 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		add_prog(t_shell *shell)
{
	t_prog		*prog;

	prog = (t_prog *)malloc(sizeof(t_prog));
	prog->prog_name = NULL;
	prog->prog_args = NULL;
	prog->flag = -1;
	prog->redirect_file = NULL;
	ft_list_push_back(&shell->progs_list, (void *)prog);
}

t_parse		*init_struct(char *str, char **env)
{
	t_parse		*parse;
	int			i;
	int			size_str;

	i = 0;
	size_str = ft_strlen(str);
	parse = (t_parse *)malloc(sizeof(t_parse)); // защитить маллок
	parse->shell = (t_shell *)malloc(sizeof(t_shell));
	parse->shell->count_progs = 1;
	parse->shell->progs_list = NULL;
	parse->str = str;
	parse->i_str = 0;
	parse->start_command = 0;
	parse->number_args = 0;
	parse->error_flag = 0;
	// parse->replace_str = NULL;
	parse->env = env;
	parse->replace_str = (char **)malloc(sizeof(char *) * (size_str + 1));
	parse->replace_str[size_str] = NULL;
	while (i < size_str)
	{
		parse->replace_str[i] = (char *)malloc(sizeof(char) * 2);
		parse->replace_str[i][0] = parse->str[i];
		parse->replace_str[i][1] = '\0';
		i++;
	}
	return (parse);
}

/*
** 		Function:			t_shell		*parse(char *str);
**
** 		Arguments			full command int string format
**
** 		return:				t_shell struct with all arguments and some vars
**
** 		Description:		the function parses the string into arguments.
**		Divides the line into commands if needed
*/

t_shell		*parse(char *str, char **env)
{
	t_parse		*parse;
	t_shell		*tmp;
	int			j;

	j = 0;
	parse = init_struct(str, env);
	// if (check_str(str))
	// 	error_output(/* something */);
	while (j < parse->shell->count_progs && parse->error_flag == 0)
	{
		add_prog(parse->shell); // создает один лист в progs_list
		line_division(parse); // парсит строку итой программы
		j++;
	}
	tmp = parse->shell;
	free_array2d(parse->replace_str);
	free(parse);
	if (parse->error_flag != 0)
	{
		free_shell(&tmp);
		return (NULL);
	}
	else
		return (tmp);
}

int			main(int argc, char **argv, char **env)
{
	int			i;
	t_shell		*shell;
	t_prog		*tmp;//

	i = 0;
	(void)argc;
	(void)argv;
	(void)env;
	printf("src = %s \n", argv[1]);
	shell = parse(argv[1], env);
	if (shell == NULL)
	{
		printf("SYNTAX ERROR\n");
		return (1);
	}
	tmp = shell->progs_list->content;
	while (tmp->prog_args[i] != NULL)
	{
		printf("%s\n", tmp->prog_args[i]);
		i++;
	}
	return (0);
}
