/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:04:18 by jaji              #+#    #+#             */
/*   Updated: 2023/03/25 02:56:49 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dupstr;

	s1_len = ft_strlen(s1);
	dupstr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dupstr)
		return (NULL);
	ft_memcpy(dupstr, s1, s1_len + 1);
	return (dupstr);
}
