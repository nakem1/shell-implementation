/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:57:09 by frariel           #+#    #+#             */
/*   Updated: 2021/06/02 20:18:48 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(int argc, char **argv, char ***envp)
{
	t_env	*list;
	t_env	*tmp;
	int		i;

	i = 0;
	list = NULL;
	convert_env(*envp, &list);
	clear_env_array(*envp);
	*envp = NULL;
	tmp = list;
	if (argc == 1)
	{
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->name, "_") != 0 || ft_strcmp(tmp->name, "?") != 0)
			{
				printf("declare -x %s", tmp->name);
				if (tmp->value != NULL)
					printf("=\"%s\"", tmp->value);
				printf("\n");
				tmp = tmp->next;
			}
		}
	}
	else
	{
		while (++i < argc)
			if (check_var(argv[i], list) == 0)
				env_push_elem(&list, argv[i]);
			else if (check_equality_sign(argv[i]) == 1)
				env_change_elem(&list, argv[i]);
	}
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
}

void	add_underscore(t_prog *prog, char ***envp, int flag)
{
	char	*command_str;
	char	**full_cmd;
	int		i;

	if (flag == 1)
	{
		i = 0;
		while (prog->prog_args[i] != NULL)
			i++;
		i--;
		command_str = NULL;
		full_cmd = NULL;
		command_str = ft_strjoin("export _=", prog->prog_args[i]);
		full_cmd = ft_split(command_str, ' ');
		export(2, full_cmd, envp);
		free(command_str);
	}
	else
	{
		full_cmd = ft_split("unset _", ' ');
		unset(2, full_cmd, envp);
	}
	clear_env_array(full_cmd);
}
