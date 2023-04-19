/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_nb_zero_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 03:27:38 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 04:51:31 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	d_nb_zero(t_print *ps)
{
	if (ps->minus)
		return (d_nb_zero_minus(ps));
	if (ps->space)
		ps->plen += ft_putchar_fd(' ', 1);
	if (ps->plus && ps->zero)
		ps->plen += ft_putchar_fd('+', 1);
	if (ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision);
	if (!ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision + 1);
	if (ps->plus && !ps->zero)
		ps->plen += ft_putchar_fd('+', 1);
	if (ps->precision > ps->width)
		zero_padding(ps, ps->precision, 0);
	else if (ps->precision)
		zero_padding(ps, ps->precision, 0);
	else if (!ps->dot)
		ps->plen += ft_putchar_fd('0', 1);
}

void	d_nb_zero_minus(t_print *ps)
{
	if (ps->plus)
		ps->plen += ft_putchar_fd('+', 1);
	if (ps->space)
		ps->plen += ft_putchar_fd(' ', 1);
	if (ps->precision > ps->width)
		zero_padding(ps, ps->precision, 0);
	else if (ps->precision)
		zero_padding(ps, ps->precision, 0);
	else if (!ps->dot)
		ps->plen += ft_putchar_fd('0', 1);
	if (ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision);
	if (!ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision + 1);
}
