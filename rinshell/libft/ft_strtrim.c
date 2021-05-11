/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:41:54 by frariel           #+#    #+#             */
/*   Updated: 2020/11/05 06:48:04 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		check_set(char c, char const *set)
{
	int		k;

	k = 0;
	if (c == '\0')
		return (1);
	while (set[k])
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

static	void	find_start_end(char const *s1, char const *set,
								int *start, int *end)
{
	int		len;
	int		k;
	int		str_start;
	int		str_end;

	len = (int)ft_strlen(s1);
	k = 0;
	str_start = 0;
	str_end = 0;
	while (s1[k])
	{
		if (!(check_set(s1[k], set)))
			str_end = k;
		k++;
	}
	while (len >= 0)
	{
		if (!(check_set(s1[len], set)))
			str_start = len;
		len--;
	}
	*start = str_start;
	*end = str_end;
}

static	void	filler(const char *s1, char *str, int start, int end)
{
	int		k;

	k = 0;
	while (start <= end)
	{
		str[k] = s1[start];
		start++;
		k++;
	}
	str[k] = '\0';
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int			str_start;
	int			str_end;
	char		*str;

	if (!s1)
		return (NULL);
	find_start_end(s1, set, &str_start, &str_end);
	if (str_end == 0 && str_start == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else if (str_end == str_start)
		str = (char*)malloc(sizeof(char) *
			(((int)ft_strlen(s1) - str_start) + 2));
	else
		str = (char*)malloc(sizeof(char) * (str_end - str_start + 2));
	if (str == 0)
		return (NULL);
	filler(s1, str, str_start, str_end);
	return (str);
}
