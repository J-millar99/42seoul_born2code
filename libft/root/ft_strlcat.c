/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:16:12 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 19:16:12 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t destsize)
{
    size_t  idx;
    size_t  destlen;

    destlen = ft_strlen(dest);
    idx = 0;
    if (destsize <= destlen)
        return (ft_strlen(src) + destsize);
    while (src[idx] && idx < destsize - 1)
    {
            dest[destlen + idx] = src[idx];
            ++idx;
    }
    dest[destlen + idx] = '\0';
    return (ft_strlen(src) + ft_strlen(dest));
}