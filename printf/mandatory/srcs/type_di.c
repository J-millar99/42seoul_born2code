/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:08:34 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_i(va_list vlist)
{
	return (type_d(vlist));
}

int	type_d(va_list vlist)
{
	int		plen;
	int		num;

	num = va_arg(vlist, int);
	plen = 0;
	if (num < 0)
		plen += write(1, "-", 1);
	plen += check_int_len(num);
	if (num >= 0)
		print_decimal_num_positive(num);
	else
		print_decimal_num_negative(num);
	return (plen);
}

void	print_decimal_num_positive(int num)
{
	if (num >= 10)
	{
		print_decimal_num_positive(num / 10);
		print_decimal_num_positive(num % 10);
	}
	else
		write(1, &"0123456789"[num % 10], 1);
}

void	print_decimal_num_negative(int num)
{
	if (num <= -10)
	{
		print_decimal_num_negative(num / 10);
		print_decimal_num_negative(num % 10);
	}
	else
		write(1, &"0123456789"[num % 10 * -1], 1);
}
