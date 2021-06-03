/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:17:33 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 21:45:33 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>

void		handle_errors(int flag_error)
{
	if (flag_error == 1)
		printf("\x1b[31mSYNTAX ERROR. PLS man ne nado dushit\x1b[0m\n");
	else if (flag_error == e_memory)
		printf("\x1b[37;43mMEMORY ERROR. Not enough memory. Free up memory \
				with a script\x1b[0m\n");
	else if (flag_error == e_file_not_found)
		printf("\x1b[4;35mNO SUCH FILE(((\x1b[0m\n");
}
