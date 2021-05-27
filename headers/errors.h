/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:04:19 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/24 17:36:20 by frariel          ###   ########.fr       */
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
