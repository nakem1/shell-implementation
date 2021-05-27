/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:25:37 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/27 14:17:59 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		int ft_strcmp
**
** Description:		ft_strcmp() functions lexicographically compare the
** null-ter-minated strings s1 and s2.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int	k;

	k = 0;
	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		k++;
	}
	return ((unsigned char)s1[k] - (unsigned char)s2[k]);
}
