/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:33:36 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/11 02:33:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
