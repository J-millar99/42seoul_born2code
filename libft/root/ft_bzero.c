/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:20:51 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 03:20:51 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_bzero(void *ptr, size_t num)
{
    size_t          idx;
    unsigned char   *str;

    if (ptr == NULL)
        return (NULL);
    idx = 0;
    str = (unsigned char *)ptr;
    while (idx < num)
    {
        str[idx] = 0;
        ++idx;
    }
    return (ptr);
}