/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:22:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/16 19:22:05 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_allocate_join(unsigned int n, unsigned int m, \
				char const *s1, char const *s2)
{
	unsigned int		i;
	unsigned int		j;
	char				*str;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * (n + m + 1))))
		return (NULL);
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < m)
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}

/*
** 		Function:         int ft_strdel
**
** 		Description:      free memory
*/

int			ft_clear_all(int fd, char **save)
{
	if (save[fd])
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (-1);
}

/*
** 		Function:         int	return_line();
**
** 		Description:      A function that returns 1
** if we read not the last line, otherwise it returns 0.
** In variable temporary we write characters after '\n'
*/

int			return_line(int fd, char **line, char **persistant)
{
	int		count;
	char	*temporary;

	count = 0;
	while (persistant[fd][count] != '\n' && persistant[fd][count] != '\0')
		count++;
	if (persistant[fd][count] == '\n')
	{
		if ((*line = ft_substr(persistant[fd], 0, count)) == NULL)
			return (ft_clear_all(fd, persistant));
		if ((temporary = ft_strdup(&persistant[fd][count + 1])) == NULL)
			return (ft_clear_all(fd, persistant));
		free(persistant[fd]);
		persistant[fd] = temporary;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(persistant[fd])))
			return (ft_clear_all(fd, persistant));
		free(persistant[fd]);
		persistant[fd] = NULL;
		return (0);
	}
}

/*
** 		Function:         int		get_next_line();
**
** 		Description:      Write a function which returns a line read from a
** file descriptor, without the newline.
*/

int			get_next_line(int fd, char **line)
{
	int				count;
	char			memory[BUFFER_SIZE + 1];
	static char		*persistant[256];
	char			*temporary;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, memory, 0) < 0)
		return (-1);
	if (!persistant[fd])
		if (!(persistant[fd] = ft_strdup("")))
			return (-1);
	while (!ft_strchr(persistant[fd], '\n') && \
					(count = read(fd, memory, BUFFER_SIZE)) > 0)
	{
		memory[count] = '\0';
		if (!(temporary = ft_strjoin(persistant[fd], memory)))
			return (ft_clear_all(fd, persistant));
		free(persistant[fd]);
		persistant[fd] = temporary;
	}
	return (return_line(fd, line, persistant));
}
