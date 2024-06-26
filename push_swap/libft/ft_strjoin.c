/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:59:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 08:38:20 by jaehyji          ###   ########.fr       */
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
	jstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!jstr)
		return (NULL);
	ft_memcpy(jstr, s1, s1_len);
	jstr[s1_len] = ' ';
	ft_memcpy(jstr + s1_len + 1, s2, s2_len);
	jstr[s1_len + 1 + s2_len] = '\0';
	return (jstr);
}
