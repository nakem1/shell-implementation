/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:41:19 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 23:12:29 by frariel          ###   ########.fr       */
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
				printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	env_list_clear(&list);
	return (0);
}
