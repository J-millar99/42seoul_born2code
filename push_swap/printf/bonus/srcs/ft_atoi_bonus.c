/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 13:03:39 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

void	skip_space_sign(const char **str, int *sign)
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
	unsigned long	num;
	int				sign;

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

int	ft_atoi_flag(const char *str, int *flag)
{
	unsigned long	num;
	int				sign;

	num = 0;
	sign = 1;
	skip_space_sign(&str, &sign);
	if (!('0' <= *str && *str <= '9'))
		*flag = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > FT_INT_MAX && sign == 1)
			*flag = 0;
		if (num > FT_INT_MIN && sign == -1)
			*flag = 0;
		str++;
	}
	if (*str)
		*flag = 0;
	return (num * sign);
}
