/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:17:37 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 13:38:18 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_c(t_print *ps)
{
	char	c;

	c = va_arg(ps->vlist, int);
	if (ps->width && !ps->minus)
		padding(ps, 1);
	if (ps->wflag == -1)
		return ;
	ps->wflag = ft_putchar_fd(c, 1);
	if (ps->wflag == -1)
		return ;
	ps->plen += ps->wflag;
	if (ps->width && ps->minus)
		padding(ps, 1);
}
