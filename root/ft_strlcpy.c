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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (idx < size - 1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}
