/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 02:57:18 by frariel           #+#    #+#             */
/*   Updated: 2020/11/02 23:53:02 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*elem;

	if ((elem = (t_list*)malloc(sizeof(t_list))) == 0)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
