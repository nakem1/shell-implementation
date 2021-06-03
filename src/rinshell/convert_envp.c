/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:15:58 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:35:05 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	convert_env(char **vars, t_env **env)
{
	int		i;

	i = 0;
	while (vars[i] != NULL)
	{
		env_push_elem(env, vars[i]);
		i++;
	}
}

void	env_push_elem(t_env **begin_env, char *str)
{
	t_env	*elem;

	elem = *begin_env;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = env_create_elem(str);
	}
	else
		*begin_env = env_create_elem(str);
}

t_env	*env_create_elem(char *str)
{
	t_env	*elem;

	elem = (t_env*)malloc(sizeof(t_env));
	elem->value = NULL;
	elem->name = NULL;
	if (check_equality_sign(str) == 0)
		elem->name = ft_strdup(str);
	else
	{
		elem->name = dup_var_name(str);
		elem->value = dup_var_value(str);
	}
	elem->next = NULL;
	return (elem);
}

void	change_elem_value(t_env *elem, int flag, char *value)
{
	char	*tmp;

	tmp = elem->value;
	if (flag == 2)
		elem->value = ft_strjoin(tmp, value);
	else
		elem->value = ft_strdup(value);
	free(tmp);
}

void	env_change_elem(t_env **begin_env, char *str, int flag)
{
	t_env	*elem;
	char	*value;
	char	*name;

	name = dup_var_name(str);
	value = dup_var_value(str);
	elem = *begin_env;
	if (elem)
	{
		while (elem)
		{
			if (ft_strcmp(elem->name, name) == 0)
			{
				change_elem_value(elem, flag, value);
				break ;
			}
			elem = elem->next;
		}
	}
	free(name);
	free(value);
}
