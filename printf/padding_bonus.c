/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:33:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 15:33:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	padding(t_print *print_Info, int occupied_len)
{
	char	space;

	space = ' ';
	if (print_Info->zero)
		space = '0';
	while (occupied_len < print_Info->width)
	{
		print_Info->plen += ft_putchar_fd(space, 1);
		occupied_len--;
	}
}

void	middle_padding(t_print *pI, int nb_len, unsigned int nb)
{
	if (pI->dot && pI->zero)
		pI->zero = 0;
	if (pI->hash && pI->width && pI->dot && nb > 0 && !pI->minus)
		pI->width -= 2;
	if ((pI->width && !pI->minus && !pI->zero)
		|| (pI->width && pI->dot && !pI->precision && !pI->minus))
	{
		if ((pI->dot && pI->precision > nb_len))
			pI->width -= pI->precision - nb_len;
		if (pI->width && pI->hash && nb && !pI->dot)
			nb_len += 2;
		padding(pI, nb_len);
	}
}

void	zero_padding(t_print *print_Info, int nb_len)
{
	if (print_Info->plus && print_Info->zero && print_Info->width > nb_len)
		print_Info->precision = print_Info->width;
	while (nb_len < print_Info->precision)
	{
		print_Info->plen += ft_putchar_fd('0', 1);
		if (print_Info->width > 0)
			print_Info->width--;
		nb_len++;
	}
}
