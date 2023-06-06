/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lx_hash_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:15:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/20 18:16:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_lx_hash(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->minus)
		return (type_lx_hash_minus(ps, nb_len, nb));
	else
		return (type_lx_hash_nminus(ps, nb_len, nb));
}

void	type_lx_hash_minus(t_print *ps, int nb_len, unsigned int nb)
{
	int		add;

	add = 2;
	if (nb == 0)
		add = 0;
	else
		ps->plen += ft_putstr_fd("0x", 1);
	zero_padding(ps, ps->precision, nb_len);
	ft_putnbr_base_fd(nb, HEXA, 1);
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision + add);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len + add);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len + add);
}

void	type_lx_hash_nminus(t_print *ps, int nb_len, unsigned int nb)
{
	int		add;

	if (ps->zero)
		return (type_lx_hash_nminus_zero(ps, nb_len, nb));
	add = 2;
	if (nb == 0)
		add = 0;
	if (ps->width > ps->precision && ps->precision >= nb_len)
		padding(ps, ps->precision + add);
	else if (ps->dot && ps->width > ps->precision && nb_len >= ps->precision)
		padding(ps, nb_len + add);
	if (nb != 0 && ps->precision > nb_len)
		ps->plen += ft_putstr_fd("0x", 1);
	zero_padding(ps, ps->precision, nb_len);
	if (!ps->dot && ps->width > nb_len)
		padding(ps, nb_len + add);
	if (nb != 0 && nb_len >= ps->precision)
		ps->plen += ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(nb, HEXA, 1);
}

void	type_lx_hash_nminus_zero(t_print *ps, int nb_len, unsigned int nb)
{
	ps->plen += ft_putstr_fd("0x", 1);
	padding(ps, nb_len + 2);
	ft_putnbr_base_fd(nb, HEXA, 1);
}
