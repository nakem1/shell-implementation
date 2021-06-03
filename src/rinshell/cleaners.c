/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:33:34 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:37:17 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	clear_fd_array(int **fd, int pipes)
{
	int		i;

	i = 0;
	while (i < pipes)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}
