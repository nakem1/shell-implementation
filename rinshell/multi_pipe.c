#include <stdlib.h>
#include "minishell.h"

void	handle_pipeline(char **envp);
void	connect_pipes(int **fd, int count);
void	exec_program(char *const command[], int **fd, int i, char **envp, int count);
int		**init_fd_array(int pipes);
void	prog_set_fd(int i, int **fd, int count);

int		main(int ac, char **av, char **envp)
{
	handle_pipeline(envp);
	return (0);
}

// /bin/ls | /bin/cat -e | /bin/cat -e

// OUTPUT:

// commands$$
// conver_envlist_to_array.c$$
// convert_envp.c$$
// copy$$
// echo.c$$

void		handle_pipeline(char **envp)
{
	int		**fd;
	int		prog_count = 3;
	char 	*const parmList1[] = {"/bin/ls", NULL};
	char 	*const parmList2[] = {"/bin/cat", "-e", NULL};
	char 	*const parmList3[] = {"/bin/cat", "-e", NULL};

	printf ("/bin/ls | /bin/cat -e | /bin/cat -e\n\n");
	if (prog_count != 1)
	{
		fd = init_fd_array(prog_count - 1);
		connect_pipes(fd, prog_count);
	}
	int i = 0;
	// while (parmList[i] != NULL)
	// {
		exec_program(parmList1, fd, i, envp, 3);
		i++;
		exec_program(parmList2, fd, i, envp, 3);
		i++;
		exec_program(parmList3, fd, i, envp, 3);
		i++;
	// }
	wait(NULL);
	// free_pipeline(&fd);
}

void	connect_pipes(int **fd, int count)
{
	int		i;

	i = 0;
	while (i < count - 1)
	{
		pipe(fd[i]);
		printf("i = %d, fd[0] = %d, fd[1] = %d \n", i, fd[i][0], fd[i][1]);
		i++;
	}
	i = 0;
	printf("\n");
}

void	prog_set_fd(int i, int **fd, int count)
{
	if (i != count - 1)
		dup2(fd[i][1], 1);
	if (i != 0)
		dup2(fd[i - 1][0], 0);
	i = 0;
	while (i < count - 1)
	{
		close(fd[i][1]);
		close(fd[i][0]);
		i++;
	}
}

void	exec_program(char *const command[], int **fd, int i, char **envp, int count)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		prog_set_fd(i, fd, count);
		execve(command[0], command, envp);
		printf("Execve error");
	}
}

int		**init_fd_array(int pipes)
{
	int	i;
	int	**fd;

	fd = NULL;
	i = 0;
	if (pipes != 0)
	{
		fd = (int**)malloc(sizeof(int*) * pipes);
		if (!fd)
			exit (1);
	}
	while (i < pipes)
	{
		fd[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	return (fd);
}

// int		count_pipes(t_list *list)
// {
// 	int		pipes;

// 	pipes = 0;
// 	while (list != NULL)
// 	{
// 		if (((t_prog *)list->content)->flag_separator == 0)
// 			pipes++;
// 		list = list->next;
// 	}
// 	return (pipes);
// }
