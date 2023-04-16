/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:02:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 21:02:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_percent(t_print *ps)
{
	if (ps->dot && ps->zero)
		ps->dot = 0;
	if (ps->width && !ps->minus)
		padding(ps, 1);
	ps->plen += ft_putchar_fd('%', 1);
	if (ps->width && ps->minus)
		padding(ps, 1);
}