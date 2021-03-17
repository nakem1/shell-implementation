/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:01:22 by lmurray           #+#    #+#             */
/*   Updated: 2020/11/05 05:34:52 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		size_t		ft_strlcat
**
** Description:		strlcat() appends string src to the end of dst.  It will
** append at most dstsize - strlen(dst) - 1 charac-ters.  It will then
** NUL-terminate, unless dstsize is 0 or the original dst string was longer
** than dstsize (in practice this should not happen as it means that either
** dstsize is incorrect or that dst is not a proper string).
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		ld;
	size_t		ls;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (dstsize < ld + 1)
		return (dstsize + ls);
	if (dstsize - ld > 0)
		ft_strlcpy(&dst[ld], src, dstsize - ld);
	return (ld + ls);
}
