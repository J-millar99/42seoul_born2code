/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:16:12 by jaji              #+#    #+#             */
/*   Updated: 2023/03/21 23:26:16 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	idx = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[idx] && dstlen + idx + 1 < dstsize)
	{
		dst[dstlen + idx] = src[idx];
		++idx;
	}
	dst[dstlen + idx] = '\0';
	return (srclen + dstlen);
}
