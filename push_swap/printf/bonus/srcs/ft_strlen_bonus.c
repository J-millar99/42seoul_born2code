/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:42:52 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 01:57:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (s[idx++] != 0)
		++len;
	return (len);
}
