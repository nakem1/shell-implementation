/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:17:52 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/03 05:09:05 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void	*ft_calloc(size_t count, size_t size
**
** Description:		The calloc() function contiguously allocates enough space
** for count objects that are size bytes of memory each and returns a pointer
** to the allocated memory.  The allocated memory is filled with  bytes of
** value zero
*/

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if (!(tmp = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(tmp, size * count);
	return (tmp);
}
