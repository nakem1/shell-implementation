/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:39:20 by frariel           #+#    #+#             */
/*   Updated: 2021/03/04 22:21:05 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if ((int)*str == ch)
			return ((char*)str);
		str++;
	}
	if (*str == ch)
		return ((char*)str);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char		*dest;
	size_t		i;
	size_t		length;

	i = 0;
	length = ft_strlen(s1);
	dest = (char*)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (0);
	if (!len || (size_t)start >= ft_strlen((char*)s))
		return (ft_strdup(""));
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
