/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:49:25 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 13:49:25 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t num)
{
    size_t          idx;
    unsigned char   *temp_dest;
    unsigned char   *temp_src;

    if (dest == NULL)
        return (0);
    temp_dest = (unsigned char *)dest;
    temp_src = (unsigned char *)src;
    if (dest < src)
    {
        idx = 0;
        while (idx < num)
        {
            temp_dest[idx] = temp_src[idx];
            ++idx;
        }
    }
    else
    {
        idx = num;
        while(idx > 0)
        {
            temp_dest[idx - 1] = temp_src[idx - 1];
            --idx;
        }
    }
    return (dest);
}