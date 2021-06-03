/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:58:36 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 02:27:23 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_built_in(int argc, char **command, char ***envp, int *exit_status)
{
	if (ft_strcmp(command[0], "echo") == 0)
		echo(argc, command);
	else if (ft_strcmp(command[0], "cd") == 0)
		cd(argc, command[1], envp, exit_status);
	else if (ft_strcmp(command[0], "pwd") == 0)
		pwd(exit_status);
	else if (ft_strcmp(command[0], "export") == 0)
		export(argc, command, envp, exit_status);
	else if (ft_strcmp(command[0], "unset") == 0)
		unset(argc, command, envp, exit_status);
	else if (ft_strcmp(command[0], "env") == 0)
		env(*envp);
	else if (ft_strcmp(command[0], "exit") == 0)
	{
		write(1, "exit\n", 5);
		exit_built_in(argc, command, exit_status);
	}
}

int		check_built_in(char **command)
{
	if (ft_strcmp(command[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(command[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(command[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(command[0], "export") == 0)
		return (1);
	else if (ft_strcmp(command[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(command[0], "env") == 0)
		return (1);
	else if (ft_strcmp(command[0], "exit") == 0)
		return (1);
	return (0);
}

int		run_path(char **command, char **envp)
{
	char	**path_arr;
	int		i;
	char	*prog_name;
	char	*tmp;

	path_arr = ft_split(get_env("PATH", envp), ':');
	if (path_arr == NULL)
		exit_and_error("command not found", command[0]);
	prog_name = ft_strjoin("/", command[0]);
	i = 0;
	while (path_arr[i] != NULL)
	{
		if (file_existence(path_arr[i], command[0], i) != -1)
		{
			tmp = command[0];
			command[0] = ft_strjoin(path_arr[i], prog_name);
			free(tmp);
			execve(command[0], command, envp);
			exit_and_error("No such file or directory", command[0]);
		}
		else
			i++;
	}
	exit_and_error("command not found", command[0]);
	return (0);
}

int		file_existence(char *path, char *name, int i)
{
	DIR				*dirp;
	struct dirent	*dp;
	size_t			len;

	dirp = opendir(path);
	if (dirp == NULL || ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
		return (-1);
	len = ft_strlen(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_namlen == len && ft_strcmp(dp->d_name, name) == 0)
		{
			(void)closedir(dirp);
			return (i);
		}
	}
	(void)closedir(dirp);
	return (-1);
}

char	*get_env(char *var, char **envp)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(var, envp[i], ft_strlen(var)) == 0)
		{
			if (envp[i][ft_strlen(var)] == '=')
				result = ft_strdup(envp[i] + ft_strlen(var) + 1);
		}
		i++;
	}
	return (result);
}
