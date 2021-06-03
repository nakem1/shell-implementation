/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:35:54 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 02:33:59 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exit_status(int exit_status, char ***envp)
{
	char	**command;

	command = NULL;
	if (exit_status == 0)
	{
		command = ft_split("export ?=0", ' ');
		special_export(2, command, envp);
		clear_env_array(command);
	}
	else
		signal_exit(envp, exit_status);
}

void	signal_exit(char ***envp, int exit_status)
{
	char	*status;
	char	**command;
	char	*str;

	if (exit_status == 2 || exit_status == 3)
		write(1, "\n", 1);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	else if (exit_status == 2)
		exit_status = 130;
	else if (exit_status == 3)
		exit_status = 131;
	status = ft_itoa(exit_status);
	str = ft_strjoin("export ?=", status);
	command = ft_split(str, ' ');
	free(str);
	free(status);
	special_export(2, command, envp);
	clear_env_array(command);
}

void	exit_built_in(int argc, char **argv, int *exit_status)
{
	int		exit_code;

	if (argc == 1)
		exit(0);
	else
	{
		if (is_str_digit(argv[1]) == 1)
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		if (argc > 2)
		{
			*exit_status = 1;
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return ;
		}
		if ((exit_code = ft_atoi(argv[1])) < 0)
			exit_code = 256 + exit_code % 256;
		else if (exit_code != 0)
			exit_code = exit_code % 256;
		exit(exit_code);
	}
}

int		is_str_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		exit_and_error(char *message, char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	write(2, ": ", 2);
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
	exit(127);
}
