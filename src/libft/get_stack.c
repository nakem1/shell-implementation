/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:46:23 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/05 16:15:13 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*get_stack(int argc, int *digits)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < argc - 1)
	{
		ft_list_push_back(&stack, &(digits[i]));
		i++;
	}
	return (stack);
}
