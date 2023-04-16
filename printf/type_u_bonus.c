/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:49:35 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 20:49:35 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_u(t_print *print_Info)
{
	unsigned int	n;
	int				nlen;

	n = va_arg(print_Info->vlist, unsigned int);
	nlen = flag_unbr_len_base(print_Info, n, 10);
	unbr_left_padding(print_Info, nlen, n);
	if (print_Info->width && !print_Info->minus && print_Info->zero)
		padding(print_Info, nlen);
	zero_padding(print_Info, nlen);
	if (print_Info->dot && !print_Info->precision && !nlen && !print_Info->minus)
		return ;
	else if (!(print_Info->dot && !print_Info->precision && !n))
		ft_putnbr_base_fd(n, DECI, 1);
	if (print_Info->width && print_Info->minus)
		padding(print_Info, nlen);
	print_Info->plen += nlen;
}

int	flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base)
{
	int	nb_len;

	if (nb == 0 && ps->dot && ps->precision == 0)
		nb_len = 0;
	else
		nb_len = unbrlen_base(nb, base);
	return (nb_len);
}

void	unbr_left_padding(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if (ps->hash && ps->width && ps->dot && nb > 0 && !ps->minus)
		ps->width -= 2;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && !ps->precision && !ps->minus))
	{
		if ((ps->dot && ps->precision > nb_len))
			ps->width -= ps->precision - nb_len;
		if (ps->width && ps->hash && nb && !ps->dot)
			nb_len += 2;
		padding(ps, nb_len);
	}
}