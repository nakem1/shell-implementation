/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:18:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/18 06:15:32 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		t_list		*ft_lstnew
**
** Description:		Allocates (with malloc(3)) and returns a new
** element.  The variable ’content’ is initialized
** with the value of the parameter ’content’.  The
** variable ’next’ is initialized to NULL.
*/

t_list		*ft_lstnew(void *content)
{
	t_list *tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
