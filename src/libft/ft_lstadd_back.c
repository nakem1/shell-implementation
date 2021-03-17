/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:19:21 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/05 01:44:44 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void ft_lstadd_back
**
** Description:		Adds the element ’new’ at the end of the list
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp1 = new;
		tmp->next = tmp1;
	}
	else
		*lst = new;
}
