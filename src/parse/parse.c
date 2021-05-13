/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:24:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/13 03:10:17 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		add_prog(t_shell *shell)
{
	t_prog		*prog;

	prog = (t_prog *)malloc(sizeof(t_prog));
	prog->prog_name = NULL;
	prog->prog_args = NULL;
	prog->flag_redirect = -1;
	prog->flag_separator = -1;
	prog->redirect_file = NULL;
	prog->redirect_fd = NONE_FD;
	ft_list_push_back(&shell->progs_list, (void *)prog);
}

t_parse		*init_struct(char *str, char **env, int *global)
{
	t_parse		*parse;
	int			i;
	int			size_str;

	i = 0;
	parse = NULL;
	size_str = ft_strlen(str);
	if (!(parse = (t_parse *)malloc(sizeof(t_parse))))
		return (NULL);
	parse->shell = (t_shell *)malloc(sizeof(t_shell));
	parse->shell->count_progs = 1;
	parse->shell->progs_list = NULL;
	parse->str = str;
	parse->i_str = *global;
	parse->start_command = 0;
	parse->number_args = 0;
	parse->error_flag = 0;
	parse->this_semicolon = 0;
	// parse->replace_str = NULL;
	parse->env = env;
	if (!(parse->replace_str = (char **)malloc(sizeof(char *) * (size_str + 1))))
		return (NULL);
	parse->replace_str[size_str] = NULL;
	while (i < size_str)
	{
		if (!(parse->replace_str[i] = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
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

int			parse(t_shell **shell, char *str, char **env, int *global)
{
	t_parse		*parse;
	// t_shell		*tmp;
	int			j;

	j = 0;
	if (!(parse = init_struct(str, env, global)))
		return (-1);
	// if (check_str(str))
	// 	error_output(/* something */);
	while (j < parse->shell->count_progs && parse->error_flag == 0 && \
			parse->this_semicolon != 1)
	{
		add_prog(parse->shell); // создает один лист в progs_list
		line_division(parse); // парсит строку итой программы
		j++;
	}
	*shell = parse->shell;
	*global = parse->i_str;
	free_array2d(parse->replace_str);
	free(parse);
	if (parse->error_flag != 0)
	{
		free_shell(shell);
		return (parse->error_flag);
	}
	else if (parse->this_semicolon == 1)
		return (-1);
	else
		return (0);
}

void		print_fn(t_shell *shell)
{
	int		i;
	int		j;
	t_prog	*tmp;
	t_list	*list;

	list = shell->progs_list;
	while (list != NULL)
	{
		j = 0;
		i = 0;
		tmp = list->content;
		while (tmp->prog_args != NULL && tmp->prog_args[j] != NULL)
		{
			printf("[%d] command [%d] word == %s\n", i, j, tmp->prog_args[j]);
			j++;
			i++;
		}
		if (tmp->flag_redirect != -1)
			printf("flag_redirect == %d\n", tmp->flag_redirect);
		if (tmp->flag_separator != -1)
			printf("flag_separator == %d\n", tmp->flag_separator);
		list = list->next;
		i++;
	}
	printf("_______________________________________________END_OF_LIST___\n\n\n");
}

int			main(int argc, char **argv, char **env)
{
	// int				i;
	int				global;
	t_shell			*shell;
	int				end_command;
	// t_prog		*tmp;
	// t_list		*list;

	// i = 0;
	end_command = 0;
	global = 0;
	(void)argc;
	(void)argv;
	(void)env;
	while ((end_command = parse(&shell, argv[1], env, &global)) == -1)
	{
		if (shell == NULL)
		{
			printf("SYNTAX ERROR\n");
			return (1);
		}
		print_fn(shell);
		free_shell(&shell);
	}
	if (end_command != 0)
	{
		handle_errors(end_command);
		return (1);
	}
	print_fn(shell);	
	while (1);
	return (0);
}
// TODO echo $?
// TODO доделать редиректы на открытие файлов в любом месте команды
// TODO протестить переделанный парсер
