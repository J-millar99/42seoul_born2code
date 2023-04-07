/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:21:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 01:21:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len(int num)
{
	int		cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

void	print_lowercase_hex_num(unsigned int num)
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

void	print_uppercase_hex_num(unsigned int num)
{
	while (num != 0)
	{
		if (num >= 16)
			print_pointer(num / 16);
		else
			write(1, "0123456789ABCDEF"[num % 16], 1);
		num /= 16;
	}
}

int	p_hex(unsigned int num, const char c_s)
{
	int	hex_len;

	hex_len = 0;
	hex_len += check_len(num);
	if (c_s == 'x')
		print_lowercase_hex_num(num);
	else
		print_uppercase_hex_num(num);
	return (hex_len);
}
