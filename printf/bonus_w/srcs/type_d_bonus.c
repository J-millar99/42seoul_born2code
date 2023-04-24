/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:32:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 15:09:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	check_ign_flag(t_print *ps, int nb)
{
	if (nb < 0)
	{
		ps->plus = 0;
		ps->space = 0;
	}
	if (ps->space)
	{
		ps->wflag = ft_putchar_fd(' ', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
}

void	check_sign(t_print *ps, int nb)
{
	if (nb < 0)
	{
		ps->wflag = ft_putchar_fd('-', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	if (ps->plus)
	{
		ps->wflag = ft_putchar_fd('+', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
}

void	type_d_minus(t_print *ps, int nb_len, int nb)
{
	if (ps->dot)
		return (type_d_minus_dot(ps, nb_len, nb));
	check_sign(ps, nb);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
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
}

void	type_d_nminus(t_print *ps, int nb_len, int nb)
{
	if (ps->dot)
		return (type_d_nminus_dot(ps, nb_len, nb));
	if (ps->zero)
		return (type_d_zero(ps, nb_len, nb));
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
	check_sign(ps, nb);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, DECI, 1);
}

void	type_d(t_print *ps)
{
	int		nb;
	int		nb_len;

	nb = va_arg(ps->vlist, int);
	if (nb == 0)
		return (d_nb_zero(ps));
	check_ign_flag(ps, nb);
	if (ps->wflag == -1)
		return ;
	nb_len = flag_nbr_len_base(nb, 10);
	if (ps->minus)
		type_d_minus(ps, nb_len, nb);
	else
		type_d_nminus(ps, nb_len, nb);
	if (ps->wflag == -1)
		return ;
	ps->plen += nb_len;
}
