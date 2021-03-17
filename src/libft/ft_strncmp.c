/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:02:48 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/03 20:32:20 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		int ft_strncmp
**
** Description:		ft_strncmp() functions lexicographically compare the
** null-ter-minated strings s1 and s2.
** The strncmp() function compares not more than n characters.  Because
** strncmp() is designed for comparing strings rather than binary data, charac-
** ters that appear after a `\0' character are not compared.
*/

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] < str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
