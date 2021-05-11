/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:35:59 by frariel           #+#    #+#             */
/*   Updated: 2021/04/05 22:06:38 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>
#include "minishell.h"
#include "libft/libft.h"

void	pwd()
{
	char dir[MAXPATHLEN];

	getcwd(dir, MAXPATHLEN);
	printf("%s\n", dir);
}

int		main(int argc, char **argv, char **envp)
{
	char 	**test;
	int		k;

	k = 0;
	// while (envp[k] != NULL)
	// {
		// printf("%s\n", envp[k]);
		// k++;
	// }

	// printf("%d\n", ft_strcmp("", "1"));
	// printf("%d\n", strcmp("", "1"));
	// test = ft_split("lalal=", '=');
	// printf("%s\n", test[0]);
	// printf("%s\n", test[1]);
	// printf("%s\n", test[2]);
	return (0);
}
