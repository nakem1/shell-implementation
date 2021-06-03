/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:00:52 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 01:46:56 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(int argc, char **argv, char ***envp, int *exit_status)
{
	t_env	*list;
	int		i;
	int		res;

	i = 1;
	res = 0;
	list = NULL;
	convert_env(*envp, &list);
	clear_env_array(*envp);
	while (i < argc)
	{
		if (check_variable_syms(argv[i]) == -1)
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			*exit_status = 1;
			break ;
		}
		del_list_elem_if(&list, argv[i]);
		i++;
	}
	*envp = convert_list(list);
	env_list_clear(&list);
}

void	special_unset(int argc, char **argv, char ***envp)
{
	t_env	*list;
	t_env	*tmp;
	int		i;
	int		res;

	i = 1;
	res = 0;
	list = NULL;
	convert_env(*envp, &list);
	clear_env_array(*envp);
	tmp = list;
	while (i < argc)
	{
		del_list_elem_if(&list, argv[i]);
		i++;
	}
	*envp = convert_list(list);
	env_list_clear(&list);
}

void	del_list_elem_if(t_env **list, char *data_ref)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *list;
	if (tmp && ft_strcmp(tmp->name, data_ref) == 0)
	{
		*list = tmp->next;
		if (tmp->value != NULL)
			free(tmp->value);
		free(tmp->name);
		free(tmp);
		return ;
	}
	while (tmp && ft_strcmp(tmp->name, data_ref) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	if (tmp->value != NULL)
		free(tmp->value);
	free(tmp->name);
	free(tmp);
}
