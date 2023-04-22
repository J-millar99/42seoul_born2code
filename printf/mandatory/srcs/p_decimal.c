/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/20 22:02:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_decimal_len(int n)
{
	int		cnt;

	cnt = 1;
	while (n / 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	print_decimal_num(int num)
{
	if (num >= 0)
	{
		if (num >= 10)
		{
			print_decimal_num(num / 10);
			print_decimal_num(num % 10);
		}
		else
			write(1, &"0123456789"[num % 10], 1);
	}
	else
	{
		if (num <= -10)
		{
			print_decimal_num(num / 10);
			print_decimal_num(num % 10);
		}
		else
			write(1, &"0123456789"[num % 10 * -1], 1);
	}
}

int	p_decimal(int num)
{
	int		num_len;

	if (num >= 0)
		num_len = 0;
	else
		num_len = write(1, "-", 1);
	num_len += check_decimal_len(num);
	print_decimal_num(num);
	return (num_len);
}
