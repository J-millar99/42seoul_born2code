/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:57:31 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 13:57:31 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize == NULL)
		return (ft_strlen(src));
	while (idx < dstsize - 1 && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		++idx;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}
