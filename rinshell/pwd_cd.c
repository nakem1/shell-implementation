/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:52:59 by frariel           #+#    #+#             */
/*   Updated: 2021/06/03 19:01:18 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(int *exit_status)
{
	char dir[MAXPATHLEN];

	if (getcwd(dir, MAXPATHLEN) == NULL)
	{
		ft_putstr_fd("minishell: pwd: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		*exit_status = 1;
	}
	else
		printf("%s\n", dir);
}

int		cd(int argc, char *path, char ***envp, int *exit_status)
{
	int		retval;
	char	*home_path;
	char	dir[MAXPATHLEN];

	getcwd(dir, MAXPATHLEN);
	home_path = get_env("HOME", *envp);
	if (argc == 1 && home_path == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	else if (argc == 1)
		retval = chdir(home_path);
	else
		retval = chdir(path);
	if (retval < 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		*exit_status = 1;
	}
	else
		set_pwd(dir, envp);
	free(home_path);
	return (0);
}

void	set_pwd(char *dir_old, char ***envp)
{
	char	dir[MAXPATHLEN];
	char	**cmd_array;
	char	*command;

	getcwd(dir, MAXPATHLEN);
	command = ft_strjoin("export OLDPWD=", dir_old);
	cmd_array = ft_split(command, ' ');
	free(command);
	special_export(2, cmd_array, envp);
	clear_env_array(cmd_array);
	command = ft_strjoin("export PWD=", dir);
	cmd_array = ft_split(command, ' ');
	free(command);
	special_export(2, cmd_array, envp);
	clear_env_array(cmd_array);
}
