/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:41:09 by frariel           #+#    #+#             */
/*   Updated: 2021/04/12 19:59:02 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int		main(int argc, char **argv, char **ppp)
{
	t_env	*list;
	t_env	*tmp;
	int		words;
	char	**env;

	char	*vars[] =
	{
		"ZSH=/Users/frariel/.oh-my-zsh",  //0     len = 20, num = 0
		"PAGER=less",					  //1
		"LESS=-R",						  //2
		"LSCOLORS=Gxfxcxdxbxegedabagacad",//3
		"P9K_SSH=0",					  //4
		"LALALAL=",
		NULL
	};
	list = NULL;
	clear_env_array(vars);
	// words = count_words(list);
	// tmp = list;
	// while (list != NULL)
	// {
	// 	printf("%s\n", list->var);
	// 	list = list->next;
	// }
	// printf("\n%d\n", words);
	copy_env(ppp, &list);
	env_push_elem(&list, "XXX=GAY");
	env_del_one(&list, "PAGER"); // Delete env var
	words = count_words(list);
	env = env_list_to_arr(list, words);
	// list = tmp;
	words = 0;
	while (env[words] != NULL)
	{
		printf("%s\n", env[words]);
		words++;
	}
	env_list_clear(&list);
	// while (1);
	return (0);
}

void	env_list_clear(t_env **begin_list)
{
	t_env	*head;
	t_env	*tmp;

	head = *begin_list;
	while (head)
	{
		tmp = head->next;
		free(head->var);
		head->var = NULL;
		free(head);
		head = tmp;
	}
	*begin_list = NULL;
}

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

char	**env_list_to_arr(t_env *env, int words)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * words + 1);
	arr[words] = NULL;
	while (i < words)
	{
		arr[i] = ft_strdup(env->var);
		env = env->next;
		i++;
	}
	return (arr);
}

void	env_del_one(t_env **begin_env, char *str)
{
	t_env	*elem;
	t_env	*tmp;

	elem = *begin_env;
	if (elem)
	{
		while (elem)
		{
			tmp = elem->next;
			if (tmp && ft_strcmp(tmp->var, str) == 0)
			{
				elem->next = tmp->next;
				free(tmp->var);
				tmp->var = NULL;
				free(tmp);
				return ;
			}
			elem = tmp;
		}
	}
}


void		copy_env(char **vars, t_env **env)
{
	int		i;

	i = 0;
	while (vars[i] != NULL)
	{
		env_push_elem(env, vars[i]);
		i++;
	}
}

int			count_words(t_env *list)
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
