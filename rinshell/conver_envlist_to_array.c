/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_envlist_to_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:07 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:14:34 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_list(t_env *env)
{
	char	**arr;
	int		words;
	int		i;
	char	*full_var;

	i = 0;
	words = count_words(env);
	arr = (char**)malloc(sizeof(char*) * words + 1);
	arr[words] = NULL;
	while (i < words)
	{
		full_var = NULL;
		if (env->value != NULL)
		{
			full_var = ft_strjoin(env->name, "=");
			arr[i] = ft_strjoin(full_var, env->value);
			free(full_var);
		}
		else
			arr[i] = ft_strdup(env->name);
		env = env->next;
		i++;
	}
	return (arr);
}

int		count_words(t_env *list)
{
	t_env	*start;
	int		i;

	if (!list)
		return (0);
	i = 1;
	start = list;
	while (start->next)
	{
		i++;
		start = start->next;
	}
	return (i);
}
