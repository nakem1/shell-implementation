/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:24:21 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/08 19:08:04 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		ft_list_push_front(&tmp, av[i]);
		i++;
	}
	return (tmp);
}
