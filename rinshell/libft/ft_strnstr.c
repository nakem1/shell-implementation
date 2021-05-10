/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:24:39 by frariel           #+#    #+#             */
/*   Updated: 2020/11/10 21:08:34 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t n)
{
	size_t	i;
	size_t	j;

	if (!hay || !need)
		return (NULL);
	i = 0;
	if (need[0] == '\0')
		return ((char*)hay);
	while (i < n && hay[i] != '\0')
	{
		j = 0;
		while ((i + j < n) && need[j] != '\0' && hay[i + j] == need[j])
			j++;
		if (need[j] == '\0')
			return ((char*)hay + i);
		i++;
	}
	return (NULL);
}
