/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:57:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 01:57:04 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
