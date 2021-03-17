/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:50:25 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/12 10:24:58 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void *ft_memchr
**
** Description:		The ft_memchr() function locates the first occurrence
** of c (converted to an unsigned char) in string s.
*/

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*str;
	unsigned char			ch;

	str = s;
	i = 0;
	ch = c;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
