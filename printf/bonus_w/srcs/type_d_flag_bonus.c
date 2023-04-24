/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:59:01 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 15:11:05 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_d_nminus_dot(t_print *ps, int nb_len, int nb)
{
	type_d_padding(ps, nb_len, nb);
	if (ps->wflag == -1)
		return ;
	check_sign(ps, nb);
	if (ps->wflag == -1)
		return ;
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
	if (ps->wflag == -1)
		return ;
}

void	type_d_minus_dot(t_print *ps, int nb_len, int nb)
{
	check_sign(ps, nb);
	if (ps->wflag == -1)
		return ;
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
	if (ps->wflag == -1)
		return ;
	type_d_padding(ps, nb_len, nb);
}

void	type_d_zero(t_print *ps, int nb_len, int nb)
{
	check_sign(ps, nb);
	if (ps->wflag == -1)
		return ;
	if (ps->width > nb_len)
	{
		if (ps->plus || nb < 0)
			padding(ps, nb_len + 1);
		else if (ps->space)
			padding(ps, nb_len + 1);
		else
			padding(ps, nb_len);
	}
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
}

void	type_d_padding(t_print *ps, int nb_len, int nb)
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
	else if (ps->width > ps->precision && nb_len >= ps->precision)
	{
		if (ps->plus || nb < 0)
			padding(ps, nb_len + 1);
		else if (ps->space)
			padding(ps, nb_len + 1);
		else
			padding(ps, nb_len);
	}
}
