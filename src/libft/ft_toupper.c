/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:21:23 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/02 06:47:37 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		ft_toupper
**
** Description:		 The toupper() function converts a lower-case letter
** to the corresponding upper-case letter.  The argument must be representable
** as an unsigned char or the value of EOF.
*/

int		ft_toupper(int c)
{
	int tmp;

	tmp = c;
	if (tmp >= 'a' && tmp <= 'z')
		tmp -= 32;
	return (tmp);
}
