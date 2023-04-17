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

void	check_nb_flag(t_print *ps, int nb)
{
	if (nb < 0)
	{
		ps->plen += ft_putchar_fd('-', 1);
		ps->plus = 0;
		ps->space = 0;
	}
	if (ps->plus)
		ps->plen += ft_putchar_fd('+', 1);
	if (ps->space)
		ps->plen += ft_putchar_fd(' ', 1);
}

void	type_d_minus(t_print *ps, int nb_len, int nb)
{
	zero_padding(ps, ps->precision, nb_len);
	ft_putnbr_base_fd(nb, DECI, 1);
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
}

void	type_d_nminus(t_print *ps, int nb_len, int nb)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	zero_padding(ps, ps->precision, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
	ft_putnbr_base_fd(nb, DECI, 1);
}

void	type_d(t_print *ps)
{
	int		nb;
	int		nb_len;

	nb = va_arg(ps->vlist, int);
	if (nb == 0 && ps->dot && ps->precision == 0)
		return (nb_zero_padding(ps));
	check_nb_flag(ps, nb);
	nb_len = flag_nbr_len_base(nb, 10);
	if (ps->minus)
		type_d_minus(ps, nb_len, nb);
	else
		type_d_nminus(ps, nb_len, nb);
	ps->plen += nb_len;
}
