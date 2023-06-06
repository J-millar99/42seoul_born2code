/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:58:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 01:58:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
