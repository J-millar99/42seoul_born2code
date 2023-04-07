/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:25:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:25:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_len(unsigned long long n)
{
	int		cnt;

	cnt = 0;
	while (n != 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

void	print_pointer(unsigned long long num)
{
	while (num != 0)
	{
		if (num >= 16)
			print_pointer(num / 16);
		else
			write(1, "0123456789abcdef"[num % 16], 1);
		num /= 16;
	}
}

int	p_pointer(unsigned long long num)
{
	int	pointer_len;

	pointer_len = 0;
	pointer_len += check_len(num);
	if (pointer_len == 0)
	{
		write(1, "(nil)", 5);
		pointer_len = 5;
	}
	else
	{
		pointer_len += write(1, "0x", 2);
		print_pointer(num);
	}
	return (pointer_len);
}
