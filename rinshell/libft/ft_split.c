/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:10:15 by frariel           #+#    #+#             */
/*   Updated: 2020/11/09 18:02:40 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int		wordcounter(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != '\0' && s[i] != c)
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
			continue ;
		}
		i++;
	}
	return (words);
}

static int		wordlen(char const *s, char c)
{
	int		n;

	n = 0;
	while (s[n] != '\0' && s[n] != c)
		n++;
	return (n);
}

static int		fail_malloc(char **str_ar, int i)
{
	int		k;

	k = 0;
	while (k < i)
	{
		free(str_ar[k]);
		k++;
	}
	free(str_ar);
	return (0);
}

static int		filler(char **str_ar, char const *s, char c, int words)
{
	int		i;
	int		y;
	int		x;

	x = 0;
	i = 0;
	while (s[i] && x < words)
	{
		y = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(str_ar[x] = (char*)malloc(sizeof(char) * wordlen(s + i, c) + 1)))
			return (fail_malloc(str_ar, x));
		while (s[i] && s[i] != c)
		{
			str_ar[x][y++] = s[i];
			if (s[++i] == '\0' || s[i] == c)
				str_ar[x++][y] = '\0';
		}
		if (s[i])
			i++;
	}
	str_ar[x] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**str_ar;
	int		words;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (!s)
		return (NULL);
	if (!(str_ar = (char**)malloc(sizeof(char*) * wordcounter(s, c) + 1)))
		return (NULL);
	words = wordcounter(s, c);
	if (filler(str_ar, s, c, words) == 0)
		return (NULL);
	return (str_ar);
}
