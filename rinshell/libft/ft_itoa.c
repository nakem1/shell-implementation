/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:10:17 by frariel           #+#    #+#             */
/*   Updated: 2020/11/10 02:31:49 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		normal_itoa(char *str, int n, int rank)
{
	int		x;

	x = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		x++;
	}
	str[rank] = '\0';
	if (n == 0)
		str[0] = 48;
	while (n != 0)
	{
		rank--;
		str[rank] = n % 10 + 48;
		n /= 10;
	}
}

static	void	special_itoa(char *str, char *num)
{
	int		n;

	n = 0;
	while (num[n])
	{
		str[n] = num[n];
		n++;
	}
	str[n] = '\0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		rank;
	int		x;

	if (n == -2147483648)
	{
		if ((str = (char*)malloc(sizeof(char) * 12)) == 0)
			return (NULL);
		special_itoa(str, "-2147483648");
		return (str);
	}
	rank = 0;
	if (n < 0 || n == 0)
		rank++;
	x = n;
	while (x != 0)
	{
		rank++;
		x /= 10;
	}
	if ((str = (char*)malloc(sizeof(char) * rank + 1)) == 0)
		return (NULL);
	normal_itoa(str, n, rank);
	return (str);
}
