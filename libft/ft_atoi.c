/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:56 by jaji              #+#    #+#             */
/*   Updated: 2023/03/25 00:25:07 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	int		result;

	idx = 0;
	sign = 1;
	result = 0;
	while (str[idx] == 32 || (9 <= str[idx] && str[idx] <= 13))
		++idx;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		++idx;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result = (result * 10) + (str[idx] - '0');
		++idx;
	}
	return (sign * result);
}
