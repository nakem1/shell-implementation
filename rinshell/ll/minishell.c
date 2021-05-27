/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:50:23 by frariel           #+#    #+#             */
/*   Updated: 2021/05/21 15:57:05 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
#include <readline/readline.h>

// extern char	**environ;
void	sig_handler(int signum)
{
	// write(1, "\n", 1);
	printf("\nminishell> ");
}

void	set_path(char **command)
{
	char	*tmp;

	tmp = NULL;
	if (*command != NULL)
	{
		tmp = *command;
		ft_strjoin(*command, "/minishell/commands");
		free(tmp);
		tmp = NULL;
	}
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;
	char 	*const parmList[] = {"ls", "-la", NULL};
	char 	**env_arr;
	// char 	**const envParms = env;
	char	**command;
	char	*path;
	pid_t	child_pid;
	pid_t	wait_res;
	int		stat_loc;
	t_env	*list;
	int		i;

	list = NULL;
	convert_env(envp, &list);
	sort_list(&list);
	env_arr = convert_list(list);
	envp = env_arr;
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	// signal(SIGINT, &sig_handler);
	// signal(SIGTSTP, &sig_handler);
	while (1)
	{
		input = readline("minishell> ");
		command = get_input(input);
		if (!command[0])
		{
		/* Handle empty commands */
			free(input);
			free(command);
			continue;
		}
		if (ft_strcmp(command[0], "cd") == 0)
		{
			if (cd(command[1]) < 0)
				perror(command[1]);
			free(command);
			free(command[0]);
			continue ;
		}
		i = 0;
		while (command[i] != NULL)
			i++;
		if (ft_strcmp(command[0], "unset") == 0)
		{
			unset(i, command, &env_arr);
			free(command);
			free(command[0]);
			continue ;
		}
		if (ft_strcmp(command[0], "export") == 0)
		{
			export(i, command, &env_arr);
			free(command);
			free(command[0]);
			continue ;
		}
		if (ft_strcmp(command[0], "env") == 0)
		{
			env(env_arr);
			free(command);
			free(command[0]);
			continue ;
		}
		if (ft_strcmp(command[0], "pwd") == 0)
		{
			pwd();
			free(command);
			free(command[0]);
			continue ;
		}
		if (ft_strcmp(command[0], "echo") == 0)
		{
			echo(i, command);
			free(command);
			free(command[0]);
			continue ;
		}
		if (ft_strcmp(command[0], "exit") == 0)
			exit (0);
		// printf("|%s|\n", command[0]);
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Fork failed\n");
			exit(1);
		}
		if (child_pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			if (execve(command[0], command, env_arr) < 0)
			{
				perror(command[0]);
				exit(1);
			}
			printf("This won't be printed if execvp is successul\n");
		}
		else
			waitpid(child_pid, &stat_loc, WUNTRACED);
		free(input);
		free(command);
	}
	return (0);
}

char	**get_input(char *input)
{
	char **command = malloc(8 * sizeof(char *));
	char *separator = " ";
	char *parsed;

	int index = 0;

	parsed = strtok(input, separator);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}
	command[index] = NULL;
	return (command);
}

void	clr_arr(char **str_ar)
{
	int		k;

	k = 0;
	while (str_ar[k] != NULL)
	{
		free(str_ar[k]);
		k++;
	}
	free(str_ar);
}

int		cd(char *path)
{
	int	retval;

	retval = chdir(path);
	if (retval < 0)
		printf("minishell: cd: %s\n", strerror(errno));
	return (retval);
}

void	pwd()
{
	char dir[MAXPATHLEN];

	getcwd(dir, MAXPATHLEN);
	printf("%s\n", dir);
}
