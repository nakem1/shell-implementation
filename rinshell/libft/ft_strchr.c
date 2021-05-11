/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:20:05 by frariel           #+#    #+#             */
/*   Updated: 2020/11/02 23:32:10 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		k;

	k = 0;
	ch = c;
	while (s[k] && s[k] != ch)
		k++;
	if (ch != '\0' && s[k])
		return ((char*)s + k);
	else if (ch == '\0')
		return ((char*)s + k);
	return (NULL);
}
