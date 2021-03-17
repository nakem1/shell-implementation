/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_digits_comma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:19:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:36:12 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			only_digits_comma(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && !str[i] && str[i] != ',')
			return (0);
		i++;
	}
	return (1);
}
