/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:42:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 16:40:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	int		idx;

	if (!str)
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
