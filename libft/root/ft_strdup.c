/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:04:18 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 23:04:18 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *str)
{
    size_t  str_len;
    char    *dupstr;

    str_len = ft_strlen(str);
    dupstr = (char *)malloc(sizeof(char) * (str_len + 1));
    if (!dupstr)
        return (NULL);
    ft_memcpy(dupstr, str, str_len + 1);
    return (dupstr);
}