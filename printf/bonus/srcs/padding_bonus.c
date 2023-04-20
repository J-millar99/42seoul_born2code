/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:33:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/20 17:48:35 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	padding(t_print *ps, int occupied_len)
{
	char	space;

	space = ' ';
	if (ps->zero)
		space = '0';
	while (ps->width > occupied_len)
	{
		ps->plen += ft_putchar_fd(space, 1);
		occupied_len++;
	}
}

void	zero_padding(t_print *ps, int max, int min)
{
	while (max > min)
	{
		ps->plen += ft_putchar_fd('0', 1);
		min++;
	}
}

/*
	dot은 type x에서 사용
*/

void	nb_zero_padding(t_print *ps)
{
	if (!ps->minus)
	{
		if (!ps->dot)
		{
			padding(ps, ps->precision + 1);
			ps->plen += ft_putchar_fd('0', 1);
		}
		else
			padding(ps, ps->precision);
	}
	else
	{
		if (!ps->dot)
		{
			ps->plen += ft_putchar_fd('0', 1);
			padding(ps, ps->precision + 1);
		}
		else
			padding(ps, ps->precision);
	}
}

void	sign_padding(t_print *ps, int occupied_len)
{
	char	space;
	int		tmp;

	tmp = ps->width;
	space = ' ';
	if (ps->zero)
		space = '0';
	if (ps->space || ps->plus)
		tmp--;
	while (tmp > occupied_len)
	{
		ps->plen += ft_putchar_fd(space, 1);
		occupied_len++;
	}
}
