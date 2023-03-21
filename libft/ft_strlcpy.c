/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:57:31 by jaji              #+#    #+#             */
/*   Updated: 2023/03/21 22:33:03 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dst == NULL)
		return (ft_strlen(src));
	while (idx + 1 < dstsize && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		++idx;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (ft_strlen(src));
}
