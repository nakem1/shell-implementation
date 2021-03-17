/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:42:58 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/08 19:03:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp_aft;
	t_list *tmp_cur;
	t_list *tmp_prev;

	tmp_prev = NULL;
	tmp_cur = *begin_list;
	while (tmp_cur)
	{
		tmp_aft = tmp_cur->next;
		tmp_cur->next = tmp_prev;
		tmp_prev = tmp_cur;
		tmp_cur = tmp_aft;
	}
	*begin_list = tmp_prev;
}
