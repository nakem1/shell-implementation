/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:46:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/02 18:13:38 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int			ft_strindx(const char *s, int c, int start)
{
	int i;
	int size;

	size = ft_strlen(s);
	i = 0;
	while (i != start && i < size)
		i++;
	while (i < size)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
