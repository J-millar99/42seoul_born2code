/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 03:54:14 by jaji              #+#    #+#             */
/*   Updated: 2023/03/22 03:57:16 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;
	size_t	s_len;

	idx = 0;
	s_len = ft_strlen(s);
	while (idx < s_len)
	{
		f(idx, &s[idx]);
		++idx;
	}
}
