/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:04:19 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/18 00:18:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum				e_errors
{
	e_memory = 2,
	e_file_not_found,
};

void		handle_errors(int flag_error);

#endif