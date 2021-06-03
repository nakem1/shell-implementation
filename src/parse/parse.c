/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:24:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/04 01:42:46 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minishell.h"

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
	prog->input_fd = NONE_FD;
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
	init_struct_norm(parse, str, env, global);
	if (!(parse->replace_str = (char **)malloc(sizeof(char *) * \
			(size_str + 1))))
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
	int			j;

	j = 0;
	if (check_empty_token(str, ';') || check_empty_token(str, '|'))
		return (1);
	if (!(parse = init_struct(str, env, global)))
		return (-1);
	while (j < parse->shell->count_progs && parse->error_flag == 0 && \
			parse->this_semicolon != 1)
	{
		add_prog(parse->shell);
		line_division(parse);
		j++;
	}
	norm_parse(parse, shell, global);
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

void		handler(char *str, char ***env)
{
	int				global;
	t_shell			*shell;
	int				end_command;

	end_command = 0;
	shell = NULL;
	global = 0;
	while ((end_command = parse(&shell, str, *env, &global)) == -1)
	{
		if (shell == NULL)
		{
			handle_errors(end_command);
			printf("SYNTAX ERROR\n");
			return ;
		}
		print_fn(shell, env);
		free_shell(&shell);
	}
	if (end_command != 0)
	{
		handle_errors(end_command);
		return ;
	}
	print_fn(shell, env);
	free_shell(&shell);
}

void		init_envp(char ***envp, char **env_start)
{
	t_env	*list;
	char	**array;
	char	dir[MAXPATHLEN];
	char	*command;

	array = NULL;
	list = NULL;
	convert_env(env_start, &list);
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
	array = ft_split("unset OLDPWD", ' ');
	special_unset(2, array, envp);
	clear_env_array(array);
	array = ft_split("export OLDPWD", ' ');
	special_export(2, array, envp);
	clear_env_array(array);
	getcwd(dir, MAXPATHLEN);
	command = ft_strjoin("export PWD=", dir);
	array = ft_split(command, ' ');
	free(command);
	special_export(2, array, envp);
	clear_env_array(array);
	increase_shlvl(envp);
	signal_exit(envp, 0);
}
