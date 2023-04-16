/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:16:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 16:16:34 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_p(t_print *print_Info)
{
	void	*ptr;
	int		ptrlen;
	int		no_print;

	no_print = 0;
	ptr = va_arg(print_Info->vlist, void *);
	if (ptr == 0 && print_Info->dot && print_Info == 0)
		ptrlen = 0;
	else
		ptrlen = unbrlen_base((unsigned long)ptr, 16) + 2;
	if (print_Info->zero)
	ft_putstr_fd("0x", 1);
	middle_padding(print_Info, ptrlen, (unsigned long)ptr);
	if (!print_Info->zero)
		ft_putstr_fd("0x", 1);
	zero_padding(print_Info, ptrlen - 2);
	if (print_Info->dot && !ptr)
		no_print = 1;
	if (ptrlen && !no_print)
		ft_putptr_base_fd((unsigned long)ptr, HEXA, 1);
	print_Info->plen += ptrlen;
	if (print_Info->width && print_Info->minus)
		padding(print_Info, ptrlen);
}