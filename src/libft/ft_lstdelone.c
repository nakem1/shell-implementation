/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:36:33 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 04:46:04 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void		ft_lstdelone
**
** Description:		Takes as a parameter an element and frees the
** memory of the element’s content using the function
** ’del’ given as a parameter and free the element.
** The memory of ’next’ must not be freed.
*/

void		ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = lst;
	(*del)(tmp->content);
	free(tmp);
}
