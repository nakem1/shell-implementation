/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:46:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/05/27 19:51:30 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int			ft_strindx(const char *s, int c, int start)
{
	int i;

	i = 0;
	while (i != start && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
