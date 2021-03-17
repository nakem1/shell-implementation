/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:17:21 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/08 19:03:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
