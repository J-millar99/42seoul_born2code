/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:21:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/18 22:07:29 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_hex_len(unsigned int num)
{
	int		cnt;

	cnt = 1;
	while (num / 16)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

void	print_lowercase_hex_num(unsigned int num)
{
	if (num >= 16)
	{
		print_lowercase_hex_num(num / 16);
		print_lowercase_hex_num(num % 16);
	}
	else
		write(1, &"0123456789abcdef"[num % 16], 1);
}

void	print_uppercase_hex_num(unsigned int num)
{
	if (num >= 16)
	{
		print_uppercase_hex_num(num / 16);
		print_uppercase_hex_num(num % 16);
	}
	else
		write(1, &"0123456789ABCDEF"[num % 16], 1);
}

int	p_hex(unsigned int num, const char c_s)
{
	int	hex_len;

	hex_len = 0;
	hex_len += check_hex_len(num);
	if (c_s == 'x')
		print_lowercase_hex_num(num);
	else
		print_uppercase_hex_num(num);
	return (hex_len);
}
