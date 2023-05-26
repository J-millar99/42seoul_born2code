/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:16:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/25 21:44:54 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

/*
	27: "0x"형식으로 출력되기 때문에 길이 + 2
	31: 0x출력전에 padding을 하는데, '0'이 존재하면 패딩은 0x이후에 해야한다
		'0'는 padding시, 0x(prefix)가 먼저 출력되고 출력된다
*/

void	type_p(t_print *ps)
{
	void	*ptr;
	int		ptrlen;

	ptr = va_arg(ps->vlist, void *);
	if (!ptr)
		return (type_p_null(ps));
	ptrlen = ft_unbrlen_base((unsigned long)ptr, 16) + 2;
	if (ps->width && !ps->zero && !ps->minus)
		padding(ps, ptrlen);
	ft_putstr_fd("0x", 1);
	if (ps->zero)
		padding(ps, ptrlen);
	if ((unsigned long)ptr != 0)
		ft_put_unbr_base_fd((unsigned long)ptr, HEXA, 1);
	ps->plen += ptrlen;
	if (ps->width && ps->minus)
		padding(ps, ptrlen);
}

void	type_p_null(t_print *ps)
{
	int		ptrlen;

	ptrlen = 3;
	if (ps->dot)
		ptrlen = 2;
	if (ps->minus)
		return (type_p_null_minus(ps));
	padding(ps, ptrlen);
	if (ps->dot)
		ps->plen += ft_putstr_fd("0x", 1);
	else
		ps->plen += ft_putstr_fd("0x0", 1);
}

void	type_p_null_minus(t_print *ps)
{
	int		ptrlen;

	ptrlen = 3;
	if (ps->dot)
		ptrlen = 2;
	if (ps->dot)
		ps->plen += ft_putstr_fd("0x", 1);
	else
		ps->plen += ft_putstr_fd("0x0", 1);
	padding(ps, ptrlen);
}