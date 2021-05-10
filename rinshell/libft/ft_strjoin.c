/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:46:41 by frariel           #+#    #+#             */
/*   Updated: 2021/03/04 22:27:30 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		dest = (char*)malloc((size + 1) * sizeof(char));
		if (!dest)
			return (0);
		while (*s1 != '\0')
			dest[i++] = *(s1++);
		while (*s2 != '\0')
			dest[i++] = *(s2++);
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
