/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:34:22 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:35:29 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
