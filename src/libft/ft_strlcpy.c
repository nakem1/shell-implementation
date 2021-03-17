/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:29:43 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 04:55:59 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		size_t strlcpy
**
** Description:		The strlcpy() functions copy and concatenate strings
** with the same input parameters and output result as snprintf(3)They are
** designed to be safer, more consistent, and less error prone replacements
** for the easily misused functions strncpy(3) and strncat(3). strlcpy() take
** the full size of the destination buffer and guarantee NUL-termination if
** there is room. Note that room for the NUL should be included in dstsize.
** strlcpy() copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;
	size_t			tmp;

	count = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (dstsize - 1 > count && src[count] != '\0')
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	tmp = ft_strlen(src);
	return (tmp);
}
