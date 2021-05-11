/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:57:09 by frariel           #+#    #+#             */
/*   Updated: 2021/04/12 20:15:56 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(int argc, char **argv, char ***envp)
{
	t_env	*list;
	t_env	*tmp;
	int		i;

	i = 0;
	list = NULL;
	convert_env(*envp, &list);
	sort_list(&list);
	clear_env_array(*envp);
	tmp = list;
	if (argc == 1)
	{
		while (tmp != NULL)
		{
			printf("declare -x %s", tmp->name);
			if (tmp->value != NULL)
				printf("=\"%s\"", tmp->value);
			printf("\n");
			tmp = tmp->next;
		}
	}
	else
	{
		while (++i < argc)
			if (check_var(argv[i], list) == 0)
				env_push_elem(&list, argv[i]);
			else if (check_equality_sign(argv[i]) == 1)
				env_change_elem(&list, argv[i]);
	}
	*envp = convert_list(list);
	env_list_clear(&list);
}
