/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:00:17 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 21:00:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_lower_x(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->vlist, unsigned int);
	nb_len = flag_unbr_len_base(ps, nb, 16);
	if (nb > 0 && ps->hash && ps->zero && !ps->dot)
		nb_len += ft_putstr_fd("0x", 1);
	unbr_left_padding(ps, nb_len, nb);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0x", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		zero_padding(ps, nb_len - 2);
	else
		zero_padding(ps, nb_len);
	if (ps->dot && !ps->precision && !nb_len && !ps->minus)
		return ;
	else if (!(ps->dot && !ps->precision && !nb))
		ft_putnbr_base_fd(nb, HEXA, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->plen += nb_len;
}

void	type_upper_x(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->vlist, unsigned int);
	nb_len = flag_unbr_len_base(ps, nb, 16);
	if (nb > 0 && ps->hash && ps->zero && !ps->dot)
		nb_len += ft_putstr_fd("0X", 1);
	unbr_left_padding(ps, nb_len, nb);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0X", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		zero_padding(ps, nb_len - 2);
	else
		zero_padding(ps, nb_len);
	if (ps->dot && !ps->precision && !nb_len && !ps->minus)
		return ;
	else if (!(ps->dot && !ps->precision && !nb))
		ft_putnbr_base_fd(nb, UPHX, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->plen += nb_len;
}