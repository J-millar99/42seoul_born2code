/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:39:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/11 21:56:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
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

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dupstr;

	if (!s1)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	dupstr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dupstr)
		return (NULL);
	ft_memcpy(dupstr, s1, s1_len + 1);
	return (dupstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*jstr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	while (s2[s2_len] != 0)
		s2_len++;
	jstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!jstr)
		return (NULL);
	if (s1)
		ft_memcpy(jstr, s1, s1_len);
	if (s2)
		ft_memcpy(jstr + s1_len, s2, s2_len);
	jstr[s1_len + s2_len] = '\0';
	return (jstr);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*result;
	int				idx;
	size_t			str_len;

	if (str == NULL)
		return (NULL);
	str_len = 0;
	while (str[str_len] != 0)
		str_len++;
	if (str_len < start)
		return (ft_strdup("\0"));
	if (str_len - start < len)
		len = str_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	idx = 0;
	while (len-- > 0 && str[start] != '\0')
		result[idx++] = str[start++];
	result[idx] = '\0';
	return (result);
}
