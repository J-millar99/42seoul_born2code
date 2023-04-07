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

static int	check_cnt(int n)
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

void	make_hex_lowercase(unsigned int n)
{
	char	numarr[8];
	int		cnt;

	cnt = check_cnt(n);
	numarr[cnt] = '\0';
	while (cnt > 0)
	{
		numarr[cnt - 1] = "0123456789abcdef"[n % 16];
		n /= 10;
		cnt--;
	}
	while (numarr[cnt])
	{
		write(1, &numarr[cnt], 1);
		cnt++;
	}
}

void	p_hex(va_list *vlist)
{
	unsigned int	num;

	num = va_arg(*vlist, unsigned int);
	make_hex_lowercase(num);
}
