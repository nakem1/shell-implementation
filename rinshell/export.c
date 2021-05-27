/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:57:09 by frariel           #+#    #+#             */
/*   Updated: 2021/05/25 16:45:44 by frariel          ###   ########.fr       */
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
	clear_env_array(*envp);
	*envp = NULL;
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
	sort_list(&list);
	*envp = convert_list(list);
	env_list_clear(&list);
}
