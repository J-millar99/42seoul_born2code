/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:32:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/25 20:30:35 by jaehyji          ###   ########.fr       */
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
		ps->plen += ft_putchar_fd(' ', 1);
}

void	check_sign(t_print *ps, int nb)
{
	if (nb < 0)
		ps->plen += ft_putchar_fd('-', 1);
	if (ps->plus)
		ps->plen += ft_putchar_fd('+', 1);
}

void	type_d_minus(t_print *ps, int nb_len, int nb)
{
	if (ps->dot)
		return (type_d_minus_dot(ps, nb_len, nb));
	check_sign(ps, nb);
	ft_putnbr_base_fd(nb, DECI, 1);
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
	check_sign(ps, nb);
	ft_putnbr_base_fd(nb, DECI, 1);
}

void	type_d(t_print *ps)
{
	int		nb;
	int		nb_len;

	nb = va_arg(ps->vlist, int);
	if (nb == 0)
		return (d_nb_zero(ps));
	check_ign_flag(ps, nb);
	nb_len = ft_nbrlen_base(nb, 10);
	if (ps->minus)
		type_d_minus(ps, nb_len, nb);
	else
		type_d_nminus(ps, nb_len, nb);
	ps->plen += nb_len;
}
