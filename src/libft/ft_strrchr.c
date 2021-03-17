/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:08:00 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/03 20:01:46 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		char *ft_strrchr
**
** Description:		The ft_strrchr() function locates the last occurrence
** of c (converted to a char)
** in the string pointed to by s.  The terminating null character is considered
** to be part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (s[ft_strlen(s)] == c)
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
