/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:53:28 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 07:06:01 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		static char *fill_str
**
** Description:		The function allocates the memory of the char array
** and fills it
*/

static char		*fill_str(char *str, char *tmp, int start, int size_str)
{
	int i;

	i = 0;
	if (!(str = (char *)malloc((sizeof(char) * (size_str - start)) + 1)))
		return (NULL);
	while (start < size_str)
	{
		str[i++] = tmp[start];
		start++;
	}
	free(tmp);
	str[i] = '\0';
	return (str);
}

static int		ft_ischr_instr(char *str, char chr)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

/*
** Function:		char			*create_tmp_str
**
** Description:		create array and fill them
*/

char			*create_tmp_str(char *s1)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char *)malloc((ft_strlen(s1) * sizeof(char)) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			*returner(char *str, char *tmp)
{
	free(tmp);
	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

/*
** Function:		char *ft_strtrim
**
** Description:		Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and the end of the string.
*/

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	char	*str;
	char	*tmp;
	size_t	end_cut;
	size_t	end_i;

	if (!s1)
		return (NULL);
	end_cut = 0;
	i = 0;
	end_i = 0;
	str = NULL;
	if (!(tmp = create_tmp_str((char *)s1)))
		return (NULL);
	while (ft_ischr_instr((char *)set, tmp[i]) == 1)
		i++;
	if (tmp[i] == '\0')
		return (returner(str, tmp));
	end_i = ft_strlen(tmp) - 1;
	while (ft_ischr_instr((char *)set, tmp[end_i--]))
		end_cut++;
	if (end_cut != 0)
		return (fill_str(str, tmp, i, ft_strlen(tmp) - end_cut));
	return (fill_str(str, tmp, i, ft_strlen(tmp)));
}
