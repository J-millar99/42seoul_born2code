/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:59:01 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/18 22:34:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_d_nminus_dot(t_print *ps, int nb_len, int nb)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
	{
		if (ps->plus || nb < 0)
			padding(ps, ps->precision + 1);
		else if (ps->space)
			padding(ps, ps->precision + 1);
		else
			padding(ps, ps->precision);
	}
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
	{
		if (ps->plus || nb < 0)
			padding(ps, nb_len + 1);
		else if (ps->space)
			padding(ps, nb_len + 1);
		else
			padding(ps, nb_len);
	}
	check_sign(ps, nb);
	zero_padding(ps, ps->precision, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
	ft_putnbr_base_fd(nb, DECI, 1);
}

void	type_d_minus_dot(t_print *ps, int nb_len, int nb)
{
	check_sign(ps, nb);
	zero_padding(ps, ps->precision, nb_len);
	ft_putnbr_base_fd(nb, DECI, 1);
	if (ps->width > ps->precision && ps->precision >= nb_len)
	{
		if (ps->plus || nb < 0)
			padding(ps, ps->precision + 1);
		else if (ps->space)
			padding(ps, ps->precision + 1);
		else
			padding(ps, ps->precision);
	}
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
	{
		if (ps->plus || nb < 0)
			padding(ps, nb_len + 1);
		else if (ps->space)
			padding(ps, nb_len + 1);
		else
			padding(ps, nb_len);
	}
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len);
}

void	type_d_zero(t_print *ps, int nb_len, int nb)
{
	check_sign(ps, nb);
	if (!ps->dot && ps->width > nb_len)
	{
		if (ps->plus || nb < 0)
			padding(ps, nb_len + 1);
		else if (ps->space)
			padding(ps, nb_len + 1);
		else
			padding(ps, nb_len);
	}
	ft_putnbr_base_fd(nb, DECI, 1);
}
