/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:06:29 by frariel           #+#    #+#             */
/*   Updated: 2020/11/04 23:09:10 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				j;

	j = len - 1;
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	if (d <= s)
		ft_memcpy(d, s, len);
	else
	{
		while (j + 1)
		{
			d[j] = s[j];
			j--;
		}
	}
	return (dst);
}
