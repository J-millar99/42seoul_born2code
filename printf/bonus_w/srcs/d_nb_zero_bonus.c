/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_nb_zero_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 03:27:38 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 15:31:02 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	d_nb_zero(t_print *ps)
{
	if (ps->minus)
		return (d_nb_zero_minus(ps));
	d_nb_zero_sign(ps);
	if (ps->wflag == -1)
		return ;
	if (ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision);
	else if (!ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision + 1);
	if (ps->wflag == -1)
		return ;
	if (ps->plus && !ps->zero)
	{
		ps->wflag = ft_putchar_fd('+', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	d_nb_zero_subf(ps);
}

void	d_nb_zero_subf(t_print *ps)
{
	if (ps->precision > ps->width)
		zero_padding(ps, ps->precision, 0);
	else if (ps->precision)
		zero_padding(ps, ps->precision, 0);
	if (ps->wflag == -1)
		return ;
	else if (!ps->dot)
	{
		ps->wflag = ft_putchar_fd('0', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
}

void	d_nb_zero_minus(t_print *ps)
{
	d_nb_zero_minus_sign(ps);
	if (ps->wflag == -1)
		return ;
	if (ps->precision > ps->width)
		zero_padding(ps, ps->precision, 0);
	else if (ps->precision)
		zero_padding(ps, ps->precision, 0);
	if (ps->wflag == -1)
		return ;
	if (!ps->dot)
	{
		ps->wflag = ft_putchar_fd('0', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	if (ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision);
	else if (!ps->dot && ps->width > ps->precision)
		sign_padding(ps, ps->precision + 1);
	if (ps->wflag == -1)
		return ;
}

void	d_nb_zero_minus_sign(t_print *ps)
{
	if (ps->plus)
	{
		ps->wflag = ft_putchar_fd('+', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	if (ps->space)
	{
		ps->wflag = ft_putchar_fd(' ', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
}

void	d_nb_zero_sign(t_print *ps)
{
	if (ps->space)
	{
		ps->wflag = ft_putchar_fd(' ', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	if (ps->plus && ps->zero)
	{
		ps->wflag = ft_putchar_fd('+', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
}
