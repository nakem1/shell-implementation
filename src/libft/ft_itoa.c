/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:16:25 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/05 16:05:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		static char
**
** Description:		reverses the string and adds minus sign
*/

static char		*ft_strrev(char *str, int count, int sign)
{
	int		i;
	char	*str1;

	if (sign == 1)
	{
		i = 0;
		if (!(str1 = (char *)ft_calloc(count * sizeof(char) + 1, 1)))
			return (NULL);
		while (count - 1 >= 0)
			str1[i++] = str[--count];
	}
	else
	{
		i = 1;
		if (!(str1 = (char *)ft_calloc(count * sizeof(char) + 2, 1)))
			return (NULL);
		while (count - 1 >= 0)
			str1[i++] = str[--count];
		str1[0] = '-';
	}
	free(str);
	return (str1);
}

/*
** Function: special_argiment
**
** Description: handles special cases. 0 and lower limit int
*/

static void		*special_argiment(int n, char **num)
{
	char	*tmp;
	int		i;

	tmp = "-2147483648";
	i = 0;
	if (n == 0)
	{
		if (!(*num = (char *)ft_calloc(2, 1)))
			return (NULL);
		num[0][0] = '0';
		return (*num);
	}
	else if (n == -2147483648)
	{
		if (!(*num = (char *)ft_calloc(12, 1)))
			return (NULL);
		while (tmp[i] != '\0')
		{
			num[0][i] = tmp[i];
			i++;
		}
		return (*num);
	}
	return (num);
}

static void		*allocate_num(int n, int *count, char *num)
{
	int tmp;

	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		*count += 1;
	}
	if (!(num = (char *)ft_calloc(*count * sizeof(char) + 1, 1)))
		return (NULL);
	return (num);
}

static int		checker(char **num, int *sign, int *n)
{
	int	x;

	x = *n;
	if (x == 0 || x == -2147483648)
	{
		if (special_argiment(x, num) != NULL)
			return (1);
		else
			return (0);
	}
	if (x < 0)
	{
		x *= -1;
		*sign = -1;
	}
	*n = x;
	return (2);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*num;
	int		sign;
	int		count;
	int		tmp;

	num = NULL;
	sign = 1;
	tmp = checker(&num, &sign, &n);
	if (tmp == 1)
		return (num);
	else if (tmp == 0)
		return (NULL);
	i = 0;
	count = 0;
	if (!(num = allocate_num(n, &count, num)))
		return (NULL);
	while (i < count)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strrev(num, count, sign));
}
