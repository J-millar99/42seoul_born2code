/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:00:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 19:34:49 by jaehyji          ###   ########.fr       */
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
