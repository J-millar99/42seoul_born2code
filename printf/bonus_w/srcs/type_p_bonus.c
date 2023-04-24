/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:16:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 14:26:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_p(t_print *ps)
{
	void	*ptr;
	int		ptrlen;

	ptr = va_arg(ps->vlist, void *);
	ptrlen = ft_unbrlen_base((unsigned long)ptr, 16) + 2;
	if (ps->width && !ps->zero && !ps->minus)
		padding(ps, ptrlen);
	if (ps->wflag == -1)
		return ;
	ps->wflag = ft_putstr_fd("0x", 1);
	if (ps->wflag == -1)
		return ;
	if (ps->zero)
		padding(ps, ptrlen);
	if (ps->wflag == -1)
		return ;
	ft_putunbr_base_fd(ps, (unsigned long)ptr, HEXA, 1);
	ps->plen += ptrlen;
	if (ps->width && ps->minus)
		padding(ps, ptrlen);
}
