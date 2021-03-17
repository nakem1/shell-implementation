/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:56 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 17:40:58 by lmurray          ###   ########.fr       */
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
		tmp->flag = 0;
		tmp->index = 0;
		tmp->next = NULL;
	}
	return (tmp);
}
