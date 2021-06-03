/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:16:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 19:03:40 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		char *ft_strjoin
**
** Description:		Allocates (with malloc(3)) and returns a new
** string, which is the result of the concatenation
** of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	size_t	tmp;
	char	*str;

	i = 0;
	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	n = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((n * sizeof(char)) + 1)))
		exit_error("memory allocation failed", "ft_strjoin");
	n = 0;
	tmp = ft_strlen(s1);
	while (n < tmp)
		str[i++] = s1[n++];
	n = 0;
	tmp = ft_strlen(s2);
	while (n < tmp)
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}


int		exit_error(char *message, char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	write(2, ": ", 2);
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
	exit(1);
}
