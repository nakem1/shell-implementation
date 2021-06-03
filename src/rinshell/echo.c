/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:47:44 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 01:22:46 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_arg(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '\0' && i != 1)
			return (2);
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				break ;
			i++;
		}
	}
	if (str[i] == '\0' && i != 1)
		return (1);
	return (0);
}

int		check_flag(int argc, char **argv)
{
	int		i;
	int		k;
	int		flag;
	int		status;

	status = 0;
	k = 0;
	flag = 0;
	i = 0;
	while (++i < argc)
	{
		if (check_arg(argv[i]) == 0)
			status = 1;
		else if (check_arg(argv[i]) == 1 && status != 1)
		{
			argv[i] = NULL;
			flag = 1;
		}
		else if (check_arg(argv[i]) == 2 && k != 1 && status != 1)
		{
			argv[i] = NULL;
			k = 1;
		}
	}
	return (flag);
}

int		echo(int argc, char **argv)
{
	int		i;
	int		n;

	n = check_flag(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (argv[i] != NULL)
		{
			ft_putstr_fd(argv[i], 1);
			if (i + 1 < argc && argv[i + 1] != NULL)
				write(1, " ", 1);
		}
		i++;
	}
	if (n == 0 || n == 2)
		write(1, "\n", 1);
	return (0);
}
