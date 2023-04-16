/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:00:17 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 21:00:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_lower_x_minus(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->hash && nb != 0)
		ps->plen += ft_putstr_fd("0x", 1);
	zero_padding(ps, ps->precision, nb_len);
	ft_putnbr_base_fd(nb, HEXA, 1);
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
}

void	type_lower_x_nminus(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (ps->hash && nb != 0)
		ps->plen += ft_putstr_fd("0x", 1);
	zero_padding(ps, ps->precision, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
	ft_putnbr_base_fd(nb, DECI, 1);
}

void	type_lower_x(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->vlist, unsigned int);
	if (nb == 0 && ps->dot && ps->precision == 0)
		return (type_x_zero(ps));
	nb_len = flag_unbr_len_base(ps, nb, 16);
	if (ps->minus)
		type_lower_x_minus(ps, nb_len, nb);
	else
		type_lower_x_nminus(ps, nb_len, nb);
	ps->plen += nb_len;
}

void	type_x_zero(t_print *ps)
{
	padding(ps, ps->precision);
}
