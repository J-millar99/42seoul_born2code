/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:00:01 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/18 14:37:11 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
