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

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	c = (char)c;
	start = (char *)s;
	while (*s != '\0')
		s++;
	while (--s != start)
	{
		if (*s == c)
			return ((char *)s);
	}
	return (NULL);
}
