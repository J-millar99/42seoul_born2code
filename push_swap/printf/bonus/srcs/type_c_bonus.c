/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:17:37 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 15:17:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

/*
	%c에 동작하는 flag는 'width', '-'
	다른 플래그는 무시된다
	'-'가 존재하지 않으면 앞에 패딩, 존재하면 뒤에 패딩
*/

void	type_c(t_print *ps)
{
	char	c;

	c = va_arg(ps->vlist, int);
	if (ps->width && !ps->minus)
		padding(ps, 1);
	ps->plen += ft_putchar_fd(c, 1);
	if (ps->width && ps->minus)
		padding(ps, 1);
}
