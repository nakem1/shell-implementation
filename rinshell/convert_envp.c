/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:15:58 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 18:55:14 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		convert_env(char **vars, t_env **env)
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

int		check_equality_sign(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '=')
			return (1);
		k++;
	}
	return (0);
}

char	*dup_var_name(const char *s1)
{
	char		*dest;
	size_t		i;
	size_t		length;

	i = 0;
	length = 0;
	while (s1[length] != '\0' && s1[length] != '=' && s1[length] != '+')
		length++;
	dest = (char*)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*dup_var_value(const char *s1)
{
	char		*dest;
	size_t		i;
	size_t		length;
	size_t		start;

	i = 0;
	length = 0;
	while (s1[length] != '=')
		length++;
	start = length + 1;
	length = ft_strlen(s1) - length;
	dest = (char*)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (s1[start] != '\0')
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

int		check_var(char *str, t_env *env)
{
	char	*name;

	name = dup_var_name(str);
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
		{
			free(name);
			return (1);
		}
		env = env->next;
	}
	free(name);
	return (0);
}

void	env_change_elem(t_env **begin_env, char *str, int flag)
{
	t_env	*elem;
	char	*value;
	char	*tmp;
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
				tmp = elem->value;
				if (flag == 2)
					elem->value = ft_strjoin(tmp, value);
				else
					elem->value = ft_strdup(value);
				free(tmp);
				break ;
			}
			elem = elem->next;
		}
	}
	free(name);
	free(value);
}

void	clear_env_array(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
}

void	env_list_clear(t_env **begin_list)
{
	t_env	*head;
	t_env	*tmp;

	head = *begin_list;
	while (head)
	{
		tmp = head->next;
		if (head->value != NULL)
			free(head->value);
		free(head->name);
		head->value = NULL;
		head->name = NULL;
		free(head);
		head = tmp;
	}
	*begin_list = NULL;
}
