/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:09:42 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_len(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	print_num(int num)
{
	while (num != 0)
	{
		if (num >= 10)
			print_pointer(num / 10);
		else
			write(1, &"0123456789"[num % 10], 1);
		num /= 10;
	}
}

int	p_decimal(int num)
{
	int		num_len;

	if (num >= 0)
		num_len = 0;
	else
		num_len = write(1, "-", 1);
	num_len += check_len(num);
	print_num(num);
	return (num_len);
}
