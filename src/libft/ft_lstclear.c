/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:42:55 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 04:54:09 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void ft_lstclear
**
** Description:		Deletes and frees the given element and every
** successor of that element, using the function ’del’
** and free(3). Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmp1;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp1 = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = tmp1;
	}
	*lst = NULL;
}
