/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:52:52 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 03:52:52 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	idx = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (idx < n)
	{
		temp_dst[idx] = temp_src[idx];
		++idx;
	}
	return (dst);
}
