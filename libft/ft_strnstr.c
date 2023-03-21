/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:33:26 by jaji              #+#    #+#             */
/*   Updated: 2023/03/20 22:33:26 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;

	if (*substr == '\0' || len == 0)
		return ((char *)str);
	while (*str && len-- > 0)
	{
		i = 0;
		while (*(str + i) == *(substr + i) && i < len)
		{
			i++;
			if (*(substr + i) == '\0')
				return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
