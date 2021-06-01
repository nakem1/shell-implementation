/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 05:57:38 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/28 15:06:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		free_array2d(char **arr)
{
	int i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void		free_prog(void *tmp)
{
	t_prog *prog;

	prog = (t_prog *)tmp;
	free_array2d(prog->prog_args);
	if (prog->redirect_file != NULL)
		free(prog->redirect_file);
	free(prog);
}

void		free_shell(t_shell **shell)
{
	t_list *tmp;

	if (*shell != NULL)
	{
		tmp = (*shell)->progs_list;
		ft_lstclear((&tmp), &free_prog);
		free(*shell);
		*shell = NULL;
	}
}
