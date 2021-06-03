/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:50:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:05:55 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_user(char **env)
{
	int			i;
	char		*name;

	i = 0;
	name = "LOGNAME=";
	while (env[i] != NULL)
	{
		if (!ft_strncmp(name, env[i], 8))
		{
			ft_putstr_fd(&env[i][8], 2);
			break ;
		}
		i++;
	}
}

void		print_pwd(char **env)
{
	int			i;
	char		*name;

	i = 0;
	name = "PWD=";
	while (env[i] != NULL)
	{
		if (!ft_strncmp(name, env[i], 4))
		{
			ft_putstr_fd(&env[i][4], 2);
			break ;
		}
		i++;
	}
}

void		prompt(char **env)
{
	ft_putstr_fd("\033[32m# \033[0m", 2);
	print_user(env);
	ft_putstr_fd("\x1b[1;33m  \\(^ヮ^)/\x1b[0m", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\x1b[1;31m$ \x1b[0m", 2);
}
