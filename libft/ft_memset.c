/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:32:58 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 00:32:58 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*str;

	idx = 0;
	str = (unsigned char *)b;
	while (idx < len)
	{
		str[idx] = (unsigned char)c;
		++idx;
	}
	return (b);
}
