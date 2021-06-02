/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:52:59 by frariel           #+#    #+#             */
/*   Updated: 2021/06/02 20:28:35 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(int *exit_status)
{
	char dir[MAXPATHLEN];

	if (getcwd(dir, MAXPATHLEN) == NULL)
	{
		printf("minishell: pwd: %s\n", strerror(errno));
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
		printf("minishell: cd: HOME not set\n");
		return (1);
	}
	else if (argc == 1)
		retval = chdir(home_path);
	else
		retval = chdir(path);
	if (retval < 0)
	{
		printf("minishell: cd: %s\n", strerror(errno));
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
	export(2, cmd_array, envp);
	clear_env_array(cmd_array);
	command = ft_strjoin("export PWD=", dir);
	cmd_array = ft_split(command, ' ');
	free(command);
	export(2, cmd_array, envp);
	clear_env_array(cmd_array);
}
