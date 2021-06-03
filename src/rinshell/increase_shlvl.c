/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:02:29 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 23:26:26 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_shlvl(char ***envp)
{
	t_env	*list;
	char	*shlvl_value;
	char	*command;
	int		shlvl_int;

	list = NULL;
	convert_env(*envp, &list);
	clear_env_array(*envp);
	if (check_var("SHLVL", list) == 0)
		env_push_elem(&list, "SHLVL=1");
	else
	{
		shlvl_int = get_shlvl(list);
		shlvl_value = ft_itoa(shlvl_int);
		if (shlvl_int == 1000)
			command = ft_strjoin(NULL, "SHLVL=");
		else
			command = ft_strjoin("SHLVL=", shlvl_value);
		env_change_elem(&list, command, 0);
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
	i = ft_atoi(str);
	if (i < 0)
		return (0);
	if (i > 1000)
	{
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		i = 0;
	}
	return (i + 1);
}
