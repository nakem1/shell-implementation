/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:56 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/19 23:40:32 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *content)
{
	t_list *tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	// if (!(tmp->content = malloc(sizeof(int))))
	// 	return (NULL);
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
