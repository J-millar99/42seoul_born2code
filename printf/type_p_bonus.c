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

/*
	type_s의 type_ston과 유사하다
	널포인터일 경우 "(nil)"이 되버린다
	'.'는 무시된다
*/

void	type_pton(t_print *ps, char *nil)
{
	int		s_len;

	s_len = ft_strlen(nil);
	if (ps->width && !ps->minus)
		padding(ps, s_len);
	ps->plen += ft_putstr_fd(nil, 1);
	if (ps->width && ps->minus)
		padding(ps, s_len);
}

/*
	45: ptr이 널일경우 분기점
	47: "0x"형식으로 출력되기 때문에 길이 + 2
	49: 0x출력전에 padding을 하는데, '0'이 존재하면 패딩은 0x이후에 해야한다
	52: '0'는 padding시, 0x(prefix)가 먼저 출력되고 출력된다
*/

void	type_p(t_print *ps)
{
	void	*ptr;
	int		ptrlen;

	ptr = va_arg(ps->vlist, void *);
	if (ptr == 0)
		return (type_pton(ps, "(nil)"));
	ptrlen = unbrlen_base((unsigned long)ptr, 8) + 2;
	if (ps->width && !ps->zero && ps->minus)
		padding(ps, ptrlen);
	ft_putstr_fd("0x", 1);
	if (ps->zero)
		padding(ps, ptrlen);
	putptr_base_fd((unsigned long)ptr, HEXA, 1);
	ps->plen += ptrlen;
	if (ps->width && ps->minus)
		padding(ps, ptrlen);
}
