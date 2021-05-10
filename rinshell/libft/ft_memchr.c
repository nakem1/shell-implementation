/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:03:36 by frariel           #+#    #+#             */
/*   Updated: 2020/11/03 02:05:46 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*res;
	unsigned int		k;
	unsigned char		c1;

	c1 = c;
	k = 0;
	res = str;
	while (k < n)
	{
		if (res[k] == c1)
			return ((void*)str + k);
		k++;
	}
	return (NULL);
}
