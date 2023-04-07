/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:32:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:32:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_cnt(unsigned int n)
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

void	ft_putnbr(unsigned int n)
{
	char	numarr[11];
	int		cnt;

	cnt = check_cnt(n);
	numarr[cnt] = '\0';
	while (cnt > 0)
	{
		numarr[cnt - 1] = (n % 10) + '0';
		n /= 10;
		cnt--;
	}
	while (numarr[cnt])
	{
		write(1, &numarr[cnt], 1);
		cnt++;
	}
}

void	p_insigned(va_list *vlist)
{
	unsigned int	num;

	num = va_arg(*vlist, unsigned int);
	ft_putnbr(num);
}
