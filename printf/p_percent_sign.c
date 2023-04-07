/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_percent_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:07:36 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 01:07:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_percent_sign(va_list *vlist)
{
	char	p_sign;

	p_sign = va_arg(*vlist, int);
	write(1, &p_sign, 1);
}
