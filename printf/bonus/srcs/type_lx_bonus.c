/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:06:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/25 21:22:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_lx(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->vlist, unsigned int);
	if (nb == 0 && ps->precision == 0)
		return (nb_zero_padding(ps));
	nb_len = ft_unbrlen_base(nb, 16);
	if (ps->hash)
		type_lx_hash(ps, nb_len, nb);
	else
	{
		if (ps->minus)
			type_lx_minus(ps, nb_len, nb);
		else
			type_lx_nminus(ps, nb_len, nb);
	}
	ps->plen += nb_len;
}

void	type_lx_minus(t_print *ps, int nb_len, unsigned int nb)
{
	zero_padding(ps, ps->precision, nb_len);
	ft_putnbr_base_fd(nb, HEXA, 1);
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
}

void	type_lx_nminus(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	zero_padding(ps, ps->precision, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
	ft_putnbr_base_fd(nb, HEXA, 1);
}
