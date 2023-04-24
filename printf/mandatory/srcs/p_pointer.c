/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:25:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/24 22:39:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_pointer_len(unsigned long n)
{
	int		cnt;

	cnt = 1;
	while (n / 16)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

void	print_pointer(unsigned long num)
{
	if (num >= 16)
	{
		print_pointer(num / 16);
		print_pointer(num % 16);
	}
	else
		write(1, &"0123456789abcdef"[num % 16], 1);
}

int	p_pointer(void *pointer)
{
	int		plen;


	plen = 0;
	if (!pointer)
		return (write(1, "0x0", 3));
	plen += write(1, "0x", 2);
	plen += check_pointer_len((unsigned long) pointer);
	print_pointer((unsigned long) pointer);
	return (plen);
}
