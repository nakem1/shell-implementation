/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:43:01 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/03 23:31:00 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void *ft_memccpy
**
** Description:		The ft_memccpy() function copies bytes from string src
** to string dst.  If the character c (as converted to an unsigned char)
** occurs in the string src, the copy stops and a pointer to the byte
** after the copy of c in the string dst is returned.  Otherwise,
** n bytes are copied, and a NULL pointer is returned. The source
** and destination strings should not overlap, as the behavior is undefined.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char				*dest1;
	const unsigned char			*src1;
	unsigned char				tmp;
	size_t						i;

	tmp = c;
	dest1 = dest;
	src1 = src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == tmp)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
