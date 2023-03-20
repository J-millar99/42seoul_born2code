/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:28:42 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 20:28:42 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    char    *start = (char *)str;

    while (*str != '\0')
        str++;
    while (--str != start)
    {
        if (*str == (char)c)
            return ((char *)str);
    }
    return (NULL);
}