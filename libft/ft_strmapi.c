/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 03:50:27 by jaji              #+#    #+#             */
/*   Updated: 2023/03/22 03:51:05 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	s_len;
	char	*fstr;

	idx = 0;
	s_len = ft_strlen(s);
	fstr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (fstr == NULL)
		return (NULL);
	while (idx < s_len)
	{
		fstr[idx] = f(idx, s[idx]);
		++idx;
	}
	fstr[idx] = '\0';
	return (fstr);
}
