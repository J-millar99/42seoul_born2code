/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 14:03:25 by jaehyji          ###   ########.fr       */
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

void	print_decimal_num_positive(int num, int *flag)
{
	int		temp;

	temp = 0;
	if (*flag)
		return ;
	if (num >= 10)
	{
		print_decimal_num_positive(num / 10, flag);
		print_decimal_num_positive(num % 10, flag);
	}
	else
		temp = write(1, &"0123456789"[num % 10], 1);
	if (temp == -1)
		*flag = 1;
}

void	print_decimal_num_negative(int num, int *flag)
{
	int		temp;

	temp = 0;
	if (*flag)
		return ;
	if (num <= -10)
	{
		print_decimal_num_negative(num / 10, flag);
		print_decimal_num_negative(num % 10, flag);
	}
	else
		temp = write(1, &"0123456789"[num % 10 * -1], 1);
	if (temp == -1)
		*flag = 1;
}

int	p_decimal(int num, int *flag)
{
	int		plen;
	int		temp;

	plen = 0;
	temp = 0;
	if (num < 0)
		temp = write(1, "-", 1);
	if (temp == -1)
		return (-1);
	plen += temp;
	plen += check_decimal_len(num);
	if (num >= 0)
		print_decimal_num_positive(num, flag);
	else
		print_decimal_num_negative(num, flag);
	return (plen);
}
