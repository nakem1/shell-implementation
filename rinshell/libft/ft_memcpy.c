/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:19:21 by frariel           #+#    #+#             */
/*   Updated: 2020/11/04 20:39:35 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*source;
	unsigned int		k;

	if (!dst && !src)
		return (NULL);
	k = 0;
	dest = dst;
	source = src;
	while (k < n)
	{
		dest[k] = source[k];
		k++;
	}
	return (dst);
}
