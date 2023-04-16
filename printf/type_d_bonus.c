/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:32:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 20:32:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_d(t_print *print_Info)
{
	int		n;
	int		nlen;

	n = va_arg(print_Info->vlist, int);
	if (n == 0 && print_Info->dot && print_Info->precision == 0)
		nlen = 0;
	else
		nlen = nbrlen_base(n, 10);
	if (n >= 0 && print_Info->plus)
		nlen += 1;
	if (n >= 0 && print_Info->space && !print_Info->plus)
		nlen += ft_putchar_fd(' ', 1);
	print_int(print_Info, (long)n, nlen);
	print_Info->plen += nlen;
}

void	print_int(t_print *ps, long n, int nlen)
{
	int_left_padding(ps, n, nlen);
	if ((ps->space && ps->precision && n >= 0)
		|| (ps->plus && ps->precision && n >= 0))
		ps->precision += 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		if (ps->dot && ps->precision > nlen && !ps->minus)
			ps->width -= ps->precision - nlen;
		else if (ps->minus && ps->width && ps->precision >= nlen)
			ps->width -= 1;
		n = -n;
		if (ps->width && !ps->minus && ps->zero)
			padding(ps, nlen);
		if (!ps->minus || (ps->minus && ps->precision >= nlen))
			nlen--;
	}
	else if (n >= 0 && ps->plus)
		ft_putchar_fd('+', 1);
	else if (ps->width && !ps->minus && ps->zero)
		padding(ps, nlen);
	zero_padding(ps, nlen);
	int_right_padding(ps, n, nlen);
}

void	int_left_padding(t_print *ps, int n, int nlen)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && (ps->precision == 0)))
	{
		if (ps->dot && ps->precision >= nlen)
		{
			ps->width -= ps->precision - nlen;
			if ((n < 0) || (ps->space && ps->dot) || (ps->plus && ps->dot))
				ps->width -= 1;
		}
		if (!ps->minus)
			padding(ps, nlen);
	}
}

void	int_right_padding(t_print *ps, long n, int nlen)
{
	if ((ps->dot && !ps->precision && !nlen && !ps->minus && !ps->plus)
		|| (ps->dot && ps->plus && (ps->precision - nlen == 0) && !ps->minus)
		|| (ps->dot && ps->plus && !ps->precision && !n && !ps->minus))
		return ;
	else if (!n && ps->dot && !ps->precision)
	{
		padding(ps, nlen);
		return ;
	}
	else
	{
		ft_putnbr_base_fd(n, DECI, 1);
		if (ps->width && ps->minus)
			padding(ps, nlen);
	}
}
