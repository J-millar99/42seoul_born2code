/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:10:44 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 21:10:44 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_strncmp(const char *str1, const char *str2, size_t len)
{
    size_t i;

    i = 0;
    while (*str1 != '\0' &&  i < len)
    {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
        i++;
    }
    return (*str1 - *str2);
}