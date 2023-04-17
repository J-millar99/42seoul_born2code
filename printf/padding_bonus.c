/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:33:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 15:33:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
	padding은 width만큼 문자를 채우는데, 차지된 길이만큼은 제외한다
*/

void	padding(t_print *print_info, int occupied_len)
{
	char	space;

	space = ' ';
	if (print_info->zero)
		space = '0';
	while (print_info->width > occupied_len)
	{
		print_info->plen += ft_putchar_fd(space, 1);
		occupied_len++;
	}
}

void	zero_padding(t_print *ps, int max, int min)
{
	while (max > min)
	{
		ps->plen += ft_putchar_fd('0', 1);
		min++;
	}
}

void	nb_zero_padding(t_print *ps)
{
	padding(ps, ps->precision);
}
