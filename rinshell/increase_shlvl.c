/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:02:29 by frariel           #+#    #+#             */
/*   Updated: 2021/06/01 20:45:09 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_shlvl(char ***envp)
{
	t_env	*list;
	char	*shlvl_value;
	char	*command;

	list = NULL;
	command = NULL;
	shlvl_value = NULL;
	convert_env(*envp, &list);
	clear_env_array(*envp);
	if (check_var("SHLVL", list) == 0)
		env_push_elem(&list, "SHLVL=1");
	else
	{
		shlvl_value = ft_itoa(get_shlvl(list));
		command = ft_strjoin("SHLVL=", shlvl_value);
		env_change_elem(&list, command);
		free(command);
		free(shlvl_value);
	}
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
}

int		get_shlvl(t_env *list)
{
	while (list->next != NULL)
	{
		if (ft_strcmp(list->name, "SHLVL") == 0)
			return (shlvl_value(list->value));
		list = list->next;
	}
	return (1);
}


int		shlvl_value(char *str)
{
	int		i;
	int		retval;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
		{
			i++;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	retval = ft_atoi(str);
	if (retval < 0)
		return (0);
	return (retval + 1);
}

//ESLI MUSOR -> 1
// ESLI < 0 -> 0
// ESLI 0 || > 0 -> + 1
// ESLI NET -> 1
