/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:57:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 08:35:21 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_space_sign(const char **str, int *sign)
{
	while ((**str == 32 || (9 <= **str && **str <= 13)))
		(*str)++;
	if (**str == '-' || **str == '+')
	{	
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	skip_space_sign(&str, &sign);
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > LLONG_MAX && sign == 1)
			return (-1);
		if (num > LLONG_MAX && sign == -1)
			return (0);
		str++;
	}
	return (num * sign);
}