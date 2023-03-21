/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:28:42 by jaji              #+#    #+#             */
/*   Updated: 2023/03/22 00:27:46 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;
	size_t	idx;

	c = (char) c;
	end = (char *)s;
	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (end[idx] == c)
			return (end + idx);
		idx--;
	}
	if (end[idx] == c)
		return (end + idx);
	return (NULL);
}