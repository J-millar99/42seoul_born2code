/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:04:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:04:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_str(va_list *vlist)
{
	char	*str;

	str = va_arg(*vlist, char *);
	write(1, str, ft_strlen(str));
}