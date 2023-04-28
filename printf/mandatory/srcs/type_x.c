/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:21:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:18:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_lx(va_list vlist)
{
	unsigned int	hexnum;
	int				plen;

	hexnum = va_arg(vlist, unsigned int);
	plen = check_unsigned_int_len(hexnum, 16);
	print_lowercase_hex_num(hexnum);
	return (plen);
}

int	type_ux(va_list vlist)
{
	unsigned int	hexnum;
	int				plen;

	hexnum = va_arg(vlist, unsigned int);
	plen = check_unsigned_int_len(hexnum, 16);
	print_uppercase_hex_num(hexnum);
	return (plen);
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
