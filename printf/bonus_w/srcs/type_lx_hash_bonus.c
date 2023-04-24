/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lx_hash_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:15:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 16:46:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_lx_hash_minus(t_print *ps, int nb_len, t_uint nb)
{
	int		add;

	add = 2;
	if (nb == 0)
		add = 0;
	else
	{
		ps->wflag = ft_putstr_fd("0x", 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, HEXA, 1);
	if (ps->wflag == -1)
		return ;
	type_lx_hash_padding(ps, nb_len, add);
	if (ps->wflag == -1)
		return ;
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len + add);
}

void	type_lx_hash_nminus(t_print *ps, int nb_len, t_uint nb)
{
	int		add;

	if (ps->zero)
		return (type_lx_hash_nminus_zero(ps, nb_len, nb));
	add = 2;
	if (nb == 0)
		add = 0;
	type_lx_hash_padding(ps, nb_len, add);
	if (ps->wflag == -1)
		return ;
	if (nb != 0 && ps->precision > nb_len)
	{
		ps->wflag = ft_putstr_fd("0x", 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	type_lx_hash_nminus_t(ps, nb_len, nb, add);
}

void	type_lx_hash_nminus_t(t_print *ps, int nb_len, t_uint nb, int add)
{
	zero_padding(ps, ps->precision, nb_len);
	if (ps->wflag == -1)
		return ;
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len + add);
	if (ps->wflag == -1)
		return ;
	if (nb != 0 && nb_len >= ps->precision)
	{
		ps->wflag = ft_putstr_fd("0x", 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	ft_putnbr_base_fd(ps, nb, HEXA, 1);
}

void	type_lx_hash_nminus_zero(t_print *ps, int nb_len, t_uint nb)
{
	ps->wflag = ft_putstr_fd("0x", 1);
	if (ps->wflag == -1)
		return ;
	ps->plen += ps->wflag;
	padding(ps, nb_len + 2);
	if (ps->wflag == -1)
		return ;
	ft_putnbr_base_fd(ps, nb, HEXA, 1);
}

void	type_lx_hash_padding(t_print *ps, int nb_len, int add)
{
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision + add);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len + add);
}
