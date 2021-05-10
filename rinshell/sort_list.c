/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:34:42 by frariel           #+#    #+#             */
/*   Updated: 2021/04/12 17:56:34 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_list(t_env **begin_env)
{
	t_env	*elem;
	t_env	*next;
	char	*tmp;

	elem = *begin_env;
	while (elem && elem->next)
	{
		next = elem->next;
		while (next)
		{
			if (ft_strcmp(elem->name, next->name) > 0)
			{
				tmp = elem->name;
				elem->name = next->name;
				next->name = tmp;
				tmp = elem->value;
				elem->value = next->value;
				next->value = tmp;
			}
			next = next->next;
		}
		elem = elem->next;
	}
}
