/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 04:23:55 by frariel           #+#    #+#             */
/*   Updated: 2020/11/02 23:30:19 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*object;

	object = malloc(size * count);
	if (object == 0)
		return (object);
	ft_bzero(object, size * count);
	return (object);
}
