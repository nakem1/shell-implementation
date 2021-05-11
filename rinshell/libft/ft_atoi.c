/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:02:44 by frariel           #+#    #+#             */
/*   Updated: 2020/11/03 06:24:24 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		k;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	k = 0;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n' ||
			str[k] == '\r' || str[k] == '\v' || str[k] == '\f')
		k++;
	if (str[k] == '-')
	{
		sign = -1;
		k++;
	}
	else if (str[k] == '+')
		k++;
	while (str[k] >= '0' && str[k] <= '9' && str[k] != '\0')
	{
		result = (result * 10) + (str[k] - 48);
		k++;
	}
	return (result * sign);
}
