/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:09:42 by jaehyji          ###   ########.fr       */
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
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_putnbr(int n)
{
	char	numarr[11];
	int		cnt;

	cnt = check_cnt(n);
	if (n < 0)
		write(1, "-", 1);
	numarr[cnt] = '\0';
	while (cnt > 0)
	{
		if (n >= 0)
			numarr[cnt - 1] = (n % 10) + '0';
		else
			numarr[cnt - 1] = (n % 10 * -1) + '0';
		n /= 10;
		cnt--;
	}
	while (numarr[cnt])
	{
		write(1, &numarr[cnt], 1);
		cnt++;
	}
}

void	p_decimal(va_list *vlist)
{
	int		num;

	num = va_arg(*vlist, int);
	ft_putnbr(num);
}
