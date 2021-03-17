/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:14:29 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/02 06:46:06 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		int ft_tolower
**
** Description:		The tolower() function converts an upper-case letter
** to the corresponding lower-case letter.  The argument must be representable
** as an unsigned char or the value of EOF.
*/

int		ft_tolower(int c)
{
	int tmp;

	tmp = c;
	if (tmp >= 'A' && tmp <= 'Z')
		tmp += 32;
	return (tmp);
}
