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

static int	check_cnt(unsigned long long n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

void	make_address(unsigned long long addr)
{
	char	numarr[8];
	int		cnt;

	cnt = check_cnt(addr);
	numarr[cnt] = '\0';
	write(1, "0x", 2);
	while (cnt > 0)
	{
		numarr[cnt - 1] = "0123456789abcdef"[addr % 16];
		addr /= 10;
		cnt--;
	}
	while (numarr[cnt])
	{
		write(1, &numarr[cnt], 1);
		cnt++;
	}
}

void	p_pointer(va_list *vlist)
{
	unsigned long long	addr;

	addr = va_arg(*vlist, unsigned long long);
	make_address(addr);
}
