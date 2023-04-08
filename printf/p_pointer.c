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

int	check_pointer_len(unsigned long long n)
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
	if (num >= 16)
	{
		print_pointer(num / 16);
		print_pointer(num % 16);
	}
	else
		write(1, &"0123456789abcdef"[num % 16], 1);
}

int	p_pointer(unsigned long long num)
{
	int	pointer_len;

	if (num == 0)
		return (write(1, "(nil)", 5));
	pointer_len = 0;
	pointer_len += write(1, "0x", 2);
	pointer_len += check_pointer_len(num);
	print_pointer(num);
	return (pointer_len);
}
