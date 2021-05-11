/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:45:14 by frariel           #+#    #+#             */
/*   Updated: 2021/05/10 16:03:54 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "minishell.h"
# include <signal.h>
# include <sys/param.h>
# include "./libft/libft.h"

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
int		cd(char *path);
void	pwd();

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

#endif
