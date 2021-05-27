/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:45:14 by frariel           #+#    #+#             */
/*   Updated: 2021/05/27 16:16:53 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
// # include "minishell.h"
# include <errno.h>
# include <signal.h>
# include <sys/param.h>
// # include "./libft/libft.h"
# include "../headers/errors.h"
# include "../headers/structs.h"
# include "../headers/parse.h"
# include "../headers/main.h"
# include "../headers/libft.h"
# include <dirent.h>


typedef struct		s_env
{
	char			*name;		// if equal != 0 &&
	char			*value;
	int				num;
	struct s_env	*next;
}					t_env;

char	**ft_split(char const *s, char c);
char	**get_input(char *input);
int		get_next_line(int fd, char **line);
void	clr_arr(char **str_ar);
int		cd(int argc, char *path, char ***envp);
void	pwd();
void	set_pwd(char *dir_old, char ***envp);

t_env	*env_create_elem(char *str);
void	env_push_elem(t_env **begin_env, char *str);
void	convert_env(char **vars, t_env **env);
void	env_list_clear(t_env **begin_list);
int		count_words(t_env *list);
void	clear_env_array(char **env);
void	env_del_one(t_env **begin_env, char *str);
char	**env_list_to_arr(t_env *env, int words);

char	*dup_var_value(const char *s1);
char	*dup_var_name(const char *s1);
int		check_equality_sign(char *str);
char	**convert_list(t_env *env);
void	env_change_elem(t_env **begin_env, char *str);
int		check_var(char *str, t_env *env);
void	sort_list(t_env **begin_env);
void	export(int argc, char **argv, char ***envp);

int		env(char **envp);
int		unset(int argc, char **argv, char ***envp);
void	del_list_elem_if(t_env **list, char *data_ref);
int		echo(int argc, char **argv);

int		check_built_in(char **command);
void	run_built_in(int argc, char **command, char ***envp);
int		run_path(char **command, char **envp);
void	run_binary(char **command, char **envp);
void	handle_pipeline(t_list *list, char ***envp, int count_progs);
void	handle_one_prog(int argc, char **command, char ***envp, int flag);
void	prog_set_fd(int i, int **fd, int count, int flag);
int		**init_fd_array(int pipes);
void	connect_pipes(int **fd, int count);

int		exit_and_error(char *message, char *command);
int		file_existence(char *path, char *name, int i);
int		check_slash(char *str);
int		print_fn(t_shell *shell, char ***envp);
void	init_envp(char ***envp, char **env_start);
char	*get_env(char *var, char **envp);

#endif
