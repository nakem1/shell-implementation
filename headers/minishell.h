/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:45:14 by frariel           #+#    #+#             */
/*   Updated: 2021/06/04 02:28:08 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <sys/param.h>
# include "errors.h"
# include "structs.h"
# include "parse.h"
# include "main.h"
# include "../src/libft/libft.h"
# include <dirent.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	int				num;
	struct s_env	*next;
}				t_env;

char			**ft_split(char const *s, char c);
char			**get_input(char *input);
void			clr_arr(char **str_ar);
int				cd(int argc, char *path, char ***envp, int *exit_status);
void			pwd(int *exit_status);
void			set_pwd(char *dir_old, char ***envp);

t_env			*env_create_elem(char *str);
void			env_push_elem(t_env **begin_env, char *str);
void			convert_env(char **vars, t_env **env);
void			env_list_clear(t_env **begin_list);
int				count_words(t_env *list);
void			clear_env_array(char **env);
void			env_del_one(t_env **begin_env, char *str);
char			**env_list_to_arr(t_env *env, int words);
void			increase_shlvl(char ***envp);
void			increase_shlvl(char ***envp);
int				get_shlvl(t_env *list);
int				shlvl_value(char *str);

char			*dup_var_value(const char *s1);
char			*dup_var_name(const char *s1);
int				check_equality_sign(char *str);
char			**convert_list(t_env *env);
void			env_change_elem(t_env **begin_env, char *str, int flag);
int				check_var(char *str, t_env *env);
void			sort_list(t_env **begin_env);
void			export(int argc, char **argv, char ***envp, int *exit_status);
void			add_underscore(t_prog *prog, char ***envp, int flag);
void			export_no_args(t_env *tmp);
void			special_export(int argc, char **argv, char ***envp);
void			export_with_args(t_env **list, int argc, char **argv,
					int *exit_status);
int				check_variable_syms(char *str);

int				env(char **envp);
void			unset(int argc, char **argv, char ***envp, int *exit_status);
void			special_unset(int argc, char **argv, char ***envp);
void			del_list_elem_if(t_env **list, char *data_ref);
int				echo(int argc, char **argv);

int				check_built_in(char **command);
void			run_built_in(int argc, char **command, char ***envp,
					int *exit_status);
int				run_path(char **command, char **envp);
void			run_binary(char **command, char **envp);
void			handle_pipeline(t_list *list, char ***envp, int count_progs,
					int *exit_status);
void			handle_one_prog(t_prog *prog, char ***envp, int flag,
					int *exit_status);
void			prog_set_fd(int i, int **fd, int count, t_prog *prog);
int				**init_fd_array(int pipes);
void			connect_pipes(int **fd, int count);
void			close_fd(int count_progs, int **fd);
void			one_prog_redirect(t_prog *prog, char ***envp, int *exit_status);
void			clear_fd_array(int **fd, int pipes);

int				exit_and_error(char *message, char *command);
int				file_existence(char *path, char *name, int i);
int				check_slash(char *str);
int				print_fn(t_shell *shell, char ***envp);
void			init_envp(char ***envp, char **env_start);
char			*get_env(char *var, char **envp);

void			set_exit_status(int exit_status, char ***envp);
void			set_signals(int flag);
void			signal_exit(char ***envp, int exit_status);
void			exit_built_in(int argc, char**argv, int *exit_status);
int				is_str_digit(char *str);

#endif
