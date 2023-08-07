/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:09:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 08:21:49 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	vlist;
	int		plen;

	plen = 0;
	va_start(vlist, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			plen += check_sp(vlist, *(format));
		}
		else
			plen += write(1, &(*format), 1);
		format++;
	}
	va_end(vlist);
	return (plen);
}

int	check_sp(va_list vlist, const char c)
{
	static t_ptr	type_arr[8] = {type_c, type_s, type_p, type_d,
		type_i, type_u, type_lx, type_ux};
	int				idx;

	idx = type_num(TYPE, c);
	if (idx < 8)
		return (type_arr[idx](vlist));
	else
		return (type_percent());
}

int	type_num(char *type, char sp)
{
	char	*type_idx;

	type_idx = ft_strchr(type, sp);
	return (type_idx - type);
}
