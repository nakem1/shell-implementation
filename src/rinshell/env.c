/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:41:19 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 01:23:58 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(char **envp)
{
	int		i;
	t_env	*list;
	t_env	*tmp;

	i = 0;
	list = NULL;
	convert_env(envp, &list);
	sort_list(&list);
	tmp = list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, "?") != 0)
			if (tmp->value != NULL)
			{
				ft_putstr_fd(tmp->name, 1);
				write(1, "=", 1);
				ft_putstr_fd(tmp->value, 1);
				write(1, "\n", 1);
			}
		tmp = tmp->next;
	}
	env_list_clear(&list);
	return (0);
}
