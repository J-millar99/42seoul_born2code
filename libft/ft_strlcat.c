/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:16:12 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 19:16:12 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	idx = 0;
	if (dstsize <= dstlen)
		return (ft_strlen(src) + dstsize);
	while (src[idx] && dstlen + idx + 1 < dstsize)
	{
		dst[dstlen + idx] = src[idx];
		++idx;
	}
	dst[dstlen + idx] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
