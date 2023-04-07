/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_addr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:08:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:08:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_addr(va_list *vlist)
{
	unsigned long long	addr;

	addr = va_arg(*vlist, unsigned long long);
	write(1, addr, 8);
}