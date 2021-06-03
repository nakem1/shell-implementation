/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:03:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/04 00:24:30 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../src/libft/libft.h"
# include "structs.h"
# include "errors.h"

typedef struct		s_parse
{
	t_shell			*shell;
	char			*str;
	char			**replace_str;
	char			**env;
	int				i_str;
	int				start_command;
	int				number_args;
	int				error_flag;
	int				this_semicolon;
}					t_parse;

typedef struct		s_norm
{
	int i;
	int j;
	int size_list;
	int flag;
}					t_norm;

void				line_division(t_parse *parse);
void				line_move(t_parse *parse, t_prog *prog);
void				redirect_line_move(t_parse *parse);
int					parse(t_shell **shell, char *str, char **env, int *global);
void				skip_spaces(t_parse *parse, int *i);
int					skip_alpha(t_parse *parse, int *i);
void				set_output_str(t_parse *parse, t_prog *prog);
void				copy_env_tostr(t_parse *parse, int i, char **prog_args,
						int *j);
int					word_counter(t_parse *parse);
int					count_letters_inword(t_parse *parse, int i);
void				handle_env(t_parse *parse);
void				handle_shielding(t_parse *parse);
void				handle_redirect(t_parse *parse, t_prog *prog);
int					open_redirect(t_parse *parse, int type,
						char *redirect_file);
void				handle_semicolon_pipe(t_parse *parse, t_prog *prog);
void				free_array2d(char **arr);
void				free_shell(t_shell **shell);
void				handle_errors(int flag_error);
int					print_fn(t_shell *shell, char ***envp);
void				set_redirect_file_utils(t_parse *parse, t_prog *prog, \
						int *start_redir, int *i_redir);
void				handle_redirect_utils(t_parse *parse, t_prog *prog);
void				copy_env_toredirect(t_parse *parse, int *i, char *file,
						int *j);
int					check_empty_token(char *str, char delim);
void				norm_parse(t_parse *parse, t_shell **shell, int *global);
void				init_struct_norm(t_parse *parse, char *str, char **env, \
						int *global);

#endif
