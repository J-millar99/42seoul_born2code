/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:53:56 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 16:51:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_strspacejoin(char const *s1, char const *s2)
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

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	int		idx;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup("\0"));
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	idx = 0;
	while (len-- > 0 && str[start] != '\0')
		result[idx++] = str[start++];
	result[idx] = '\0';
	return (result);
}

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
	jstr[s1_len + 1 + s2_len] = '\0';
	return (jstr);
}

size_t	ft_strlen(const char *s)
{
	int		idx;
	size_t	len;

	if (!s)
		return (0);
	idx = 0;
	len = 0;
	while (s[idx++] != 0)
		++len;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	idx = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (idx < n)
	{
		temp_dst[idx] = temp_src[idx];
		++idx;
	}
	return (dst);
}
