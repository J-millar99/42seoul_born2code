/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:02:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/25 18:26:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	type_percent(t_print *ps)
{
	if (ps->width && !ps->minus)
		padding(ps, 1);
	ps->plen += ft_putchar_fd('%', 1);
	if (ps->width && ps->minus)
		padding(ps, 1);
}
