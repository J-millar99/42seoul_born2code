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
