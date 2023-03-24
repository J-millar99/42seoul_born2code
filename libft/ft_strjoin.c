/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:12:08 by jaji              #+#    #+#             */
/*   Updated: 2023/03/25 02:56:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*jstr;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	jstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!jstr)
		return (NULL);
	ft_memcpy(jstr, s1, s1_len);
	ft_memcpy(jstr + s1_len, s2, s2_len);
	jstr[s1_len + s2_len] = '\0';
	return (jstr);
}
