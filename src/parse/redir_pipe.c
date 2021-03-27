/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 08:11:09 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/27 08:28:29 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		redirect_pipe(t_parse *parse, t_prog *prog)
{
	if (parse->replace_str[parse->i_str][0] == '|')
		prog->flag = e_pipe;
}
