/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:02:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 15:38:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_percent(t_print *ps)
{
	if (ps->dot && ps->zero)
		ps->dot = 0;
	if (ps->width && !ps->minus)
		padding(ps, 1);
	if (ps->wflag == -1)
		return ;
	ps->wflag = ft_putchar_fd('%', 1);
	if (ps->wflag == -1)
		return ;
	ps->plen += ps->wflag;
	if (ps->width && ps->minus)
		padding(ps, 1);
}
