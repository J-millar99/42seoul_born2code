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

void    *ft_memset(void *ptr, int value, size_t num)
{
    size_t          idx;
    unsigned char   *str;

    if (ptr == NULL)
        return (NULL);
    idx = 0;
    str = (unsigned char *)ptr;
    while (idx < num)
    {
        str[idx] = (unsigned char)value;
        ++idx;
    }
    return (ptr);
}