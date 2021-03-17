/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:55:21 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/03 18:43:08 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Function:		void *ft_memcpy
**
** Description:		The ft_memcpy() function copies n bytes from memory area
** src to memory area dst. If dst and src overlap, behavior is undefined.
** Applications in which dst and src might overlap should use memmove(3)
** instead.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char				*dest1;
	unsigned const char			*src1;
	unsigned int				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = dest;
	src1 = src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
