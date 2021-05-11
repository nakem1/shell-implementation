/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:45:11 by frariel           #+#    #+#             */
/*   Updated: 2020/11/02 23:31:44 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	unsigned int		k;

	k = 0;
	c1 = s1;
	c2 = s2;
	while (k < n)
	{
		if (c1[k] != c2[k])
			return (c1[k] - c2[k]);
		k++;
	}
	return (0);
}
