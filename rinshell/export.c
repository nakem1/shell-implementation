/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:57:09 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 18:55:35 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(int argc, char **argv, char ***envp, int *exit_status)
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
		export_no_args(tmp);
	else
		export_with_args(&list, argc, argv, exit_status);
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
}

void	special_export(int argc, char **argv, char ***envp)
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
		export_no_args(tmp);
	else
	{
		while (++i < argc)
			if (check_var(argv[i], list) == 0)
				env_push_elem(&list, argv[i]);
			else if (check_equality_sign(argv[i]) == 1)
				env_change_elem(&list, argv[i], 0);
	}
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
}

void	export_no_args(t_env *tmp)
{
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, "_") != 0 && ft_strcmp(tmp->name, "?") != 0)
		{
			printf("declare -x %s", tmp->name);
			if (tmp->value != NULL)
				printf("=\"%s\"", tmp->value);
			printf("\n");
		}
		tmp = tmp->next;
	}
}

int		check_variable_syms(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=' && str[i] != '+')
	{
		if (i == 0 && !(str[i] >= 'A' && str[i] <= 'z') && str[i] != '_')
			return (-1);
		if (!((str[i] >= 'A' && str[i] <= 'z') ||
			(str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
			return (-1);
		i++;
	}
	if (str[0] == '+' || str[0] == '=')
		return (-1);
	if (str[i] != '\0' && str[i] == '+')
		return (2);
	return (0);
}

void	export_with_args(t_env **list, int argc, char **argv, int *exit_status)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (check_variable_syms(argv[i]) == -1)
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			*exit_status = 1;
			return ;
		}
		if (check_var(argv[i], *list) == 0)
			env_push_elem(list, argv[i]);
		else if (check_equality_sign(argv[i]) == 1)
			env_change_elem(list, argv[i], check_variable_syms(argv[i]));
		i++;
	}
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
		special_export(2, full_cmd, envp);
		free(command_str);
	}
	else
	{
		full_cmd = ft_split("unset _", ' ');
		unset(2, full_cmd, envp);
	}
	clear_env_array(full_cmd);
}
