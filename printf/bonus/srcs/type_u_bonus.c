/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:49:35 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 03:53:01 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

/*
	비교문자열길이는 precision과 nb_len에 의해 결정된다
	두 합이 width보다 작으면 공백으로 채운다
	precision이 nb_len보다 크면 '-'에 따라 '0'으로 채운다
	width는 제한선이지만 nb_len과 precision보다 작으면 역할을 못한다.
*/

void	type_u_minus(t_print *ps, int nb_len, unsigned int nb)
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

void	type_u_nminus(t_print *ps, int nb_len, unsigned int nb)
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

void	type_u(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->vlist, unsigned int);
	if (nb == 0 && ps->dot && ps->precision == 0)
		return (nb_zero_padding(ps));
	nb_len = flag_unbr_len_base(ps, nb, 10);
	if (ps->minus)
		type_u_minus(ps, nb_len, nb);
	else
		type_u_nminus(ps, nb_len, nb);
	ps->plen += nb_len;
}
