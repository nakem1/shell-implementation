/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:33:30 by frariel           #+#    #+#             */
/*   Updated: 2020/10/31 22:24:00 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *str, int val, size_t len)
{
	unsigned char		*p;
	unsigned int		n;

	n = 0;
	p = str;
	while (len > n)
	{
		p[n] = val;
		n++;
	}
	return (str);
}
