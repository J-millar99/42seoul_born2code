/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:09:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/04 17:09:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_conversion_specifier(va_list vlist, const char c_s)
{
	int	print_num;

	print_num = -1;
	if (c_s == 'c')
		print_num = p_char(va_arg(vlist, int));
	else if (c_s == 's')
		print_num = p_str(va_arg(vlist, char *));
	else if (c_s == 'p')
		print_num = p_pointer(va_arg(vlist, unsigned long long));
	else if (c_s == 'd' || c_s == 'i')
		print_num = p_decimal(va_arg(vlist, int));
	else if (c_s == 'u')
		print_num = p_unsigned(va_arg(vlist, unsigned int));
	else if (c_s == 'x' || c_s == 'X')
		print_num = p_hex(va_arg(vlist, unsigned int), c_s);
	else if (c_s == '%')
		print_num = write(1, "%", 1);
	return (print_num);
}

int	ft_printf(const char *format, ...)
{
	va_list	vlist;
	int		temp;
	int		plen;
	int		i;

	i = 0;
	plen = 0;
	va_start(vlist, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = p_conversion_specifier(vlist, format[++i]);
			if (temp == -1)
				return (-1);
		}
		else
			temp = p_char(format[i]);
		plen += temp;
		i++;
	}
	va_end(vlist);
	return (plen);
}
