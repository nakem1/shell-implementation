/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:17:12 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 04:47:02 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		t_list *ft_lstlast
**
** Description:		Returns the last element of the list
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return (tmp);
	}
	else
		return (0);
}
