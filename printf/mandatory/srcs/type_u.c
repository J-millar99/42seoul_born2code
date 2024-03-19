/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:32:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:18:51 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_u(va_list vlist)
{
	unsigned int	num;
	int				plen;

	num = va_arg(vlist, unsigned int);
	plen = check_unsigned_int_len(num, 10);
	print_unsigned_num(num);
	return (plen);
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
