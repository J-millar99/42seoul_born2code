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

void    *ft_memcpy(void *dest, const void *src, size_t num)
{
    size_t          idx;
    unsigned char   *temp_dest;
    unsigned char   *temp_src;

    if (dest == NULL && src == NULL)
        return (0);
    idx = 0;
    temp_dest = (unsigned char *)dest;
    temp_src = (unsigned char *)src;
    while (idx < num)
    {
        temp_dest[idx] = temp_src[idx];
        ++idx;
    }
    return (dest);
}