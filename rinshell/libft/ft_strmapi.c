/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:21:51 by frariel           #+#    #+#             */
/*   Updated: 2020/11/05 01:15:20 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	unsigned int	len;
	char			*str;

	if (!s)
		return (NULL);
	k = 0;
	len = ft_strlen(s);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (s[k])
	{
		str[k] = (*f)(k, s[k]);
		k++;
	}
	str[k] = '\0';
	return (str);
}
