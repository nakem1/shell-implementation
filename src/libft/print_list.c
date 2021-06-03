/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 03:15:42 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:09:10 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *list)
{
	int		i;
	t_list	*tmp;
	char	*str;

	i = 1;
	tmp = list;
	str = malloc(2);
	while (tmp != NULL)
	{
		str[0] = i + '0';
		str[1] = ' ';
		ft_putstr_fd(str, 1);
		ft_putstr_fd(tmp->content, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
		i++;
	}
}
