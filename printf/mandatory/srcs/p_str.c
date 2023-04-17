/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:04:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:04:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	p_str(char *str)
{
	ssize_t	idx;

	if (!str)
		return (write(1, "(null)", 6));
	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		++idx;
	}
	return (idx);
}
