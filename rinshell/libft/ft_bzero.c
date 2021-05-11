/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:06:43 by frariel           #+#    #+#             */
/*   Updated: 2020/11/02 23:30:17 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char		*p;
	unsigned int		n;

	n = 0;
	p = str;
	while (n < len)
	{
		p[n] = '\0';
		n++;
	}
}
