/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:00:34 by jaji              #+#    #+#             */
/*   Updated: 2023/03/22 01:17:10 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	int		idx;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup("\0"));
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	idx = 0;
	while (len-- > 0 && str[start] != '\0')
		result[idx++] = str[start++];
	result[idx] = '\0';
	return (result);
}
