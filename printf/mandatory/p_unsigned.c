/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:32:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:32:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_unsigned_len(unsigned int num)
{
	int		cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

void	print_unsigned_num(unsigned int num)
{
	if (num >= 10)
	{
		print_unsigned_num(num / 10);
		print_unsigned_num(num % 10);
	}
	else
		write(1, &"0123456789"[num % 10], 1);
}

int	p_unsigned(unsigned int num)
{
	unsigned int	num_len;

	num_len = 0;
	num_len += check_unsigned_len(num);
	print_unsigned_num(num);
	return (num_len);
}