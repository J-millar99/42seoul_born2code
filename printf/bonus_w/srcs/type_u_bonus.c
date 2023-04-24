/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:49:35 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 16:42:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_u_minus(t_print *ps, int nb_len, t_uint nb)
{
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
	if (ps->wflag == -1)
		return ;
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (ps->wflag == -1)
		return ;
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
}

void	type_u_nminus(t_print *ps, int nb_len, t_uint nb)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len);
	if (ps->wflag == -1)
		return ;
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	if (!ps->dot && ps->width > nb_len)
	{
		padding(ps, nb_len);
		if (ps->wflag == -1)
			return ;
	}
	ft_putnbr_base_fd(ps, nb, DECI, 1);
}

void	type_u(t_print *ps)
{
	t_uint	nb;
	int		nb_len;

	nb = va_arg(ps->vlist, t_uint);
	if (nb == 0 && ps->precision == 0)
		return (nb_zero_padding(ps));
	nb_len = flag_unbr_len_base(ps, nb, 10);
	if (ps->minus)
		type_u_minus(ps, nb_len, nb);
	else
		type_u_nminus(ps, nb_len, nb);
	if (ps->wflag == -1)
		return ;
	ps->plen += nb_len;
}
