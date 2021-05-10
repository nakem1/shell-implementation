/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:43:01 by frariel           #+#    #+#             */
/*   Updated: 2020/11/03 01:59:32 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*source;
	unsigned char		c1;
	size_t				k;

	c1 = c;
	k = 0;
	dest = dst;
	source = src;
	while (k < n)
	{
		dest[k] = source[k];
		if (source[k] == c1)
			return (dst + (++k));
		k++;
	}
	return (NULL);
}
