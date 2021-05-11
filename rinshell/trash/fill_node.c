/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:50:55 by frariel           #+#    #+#             */
/*   Updated: 2021/04/05 17:27:16 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		fill_node(t_env *elem, char *str)
{
	int		i;
	int		equal;

	elem->equal = 0;
	elem->value = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=' && elem->equal == 0)
			elem->equal = 1;
		i++;
	}
	if (str[i] == '\0' )
}
