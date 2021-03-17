/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:50:57 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 04:58:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void		*ft_memmove
**
** Description:		The memmove() function copies len bytes from string
** src to string dst.  The two strings may overlap; the copy is always done
** in a non-destructive manner
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = len - 1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s >= d)
		ft_memcpy(d, s, len);
	else
	{
		while (i + 1)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
