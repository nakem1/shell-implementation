/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:25:37 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:37:03 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		int ft_strcmp
**
** Description:		ft_strcmp() functions lexicographically compare the
** null-ter-minated strings s1 and s2.
*/

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] < str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
