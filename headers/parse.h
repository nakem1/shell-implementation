/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:03:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/11 00:46:30 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "structs.h"

enum				e_errors
{
	e_memory = 2,
	e_file_not_found,
};

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
	// int				count_quotes;
}					t_parse;

void		line_division(t_parse *parse);
void		line_move(t_parse *parse, t_prog *prog);
void		redirect_line_move(t_parse *parse);
int			parse(t_shell **shell, char *str, char **env, int *global);
void		skip_spaces(t_parse *parse, int *i);
int			skip_alpha(t_parse *parse, int *i);
void		set_output_str(t_parse *parse, t_prog *prog);
void		copy_env_tostr(t_parse *parse, int i, char **prog_args, int *j);
int			word_counter(t_parse *parse);
int			count_letters_inword(t_parse *parse, int i);
void		handle_env(t_parse *parse);
void		handle_shielding(t_parse *parse);
void		handle_redirect(t_parse *parse, t_prog *prog);
int			open_redirect(t_parse *parse, int type, char *redirect_file);
void		handle_semicolon_pipe(t_parse *parse, t_prog *prog);
void		free_array2d(char **arr);
void		free_shell(t_shell **shell);
void		handle_errors(int flag_error);

#endif
