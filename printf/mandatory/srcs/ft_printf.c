/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:09:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 12:51:27 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	p_conversion_specifier(va_list vlist, const char c_s)
{
	int		print_num;
	int		flag;

	flag = 0;
	print_num = -1;
	if (c_s == 'c')
		print_num = p_char(va_arg(vlist, int));
	else if (c_s == 's')
		print_num = p_str(va_arg(vlist, char *));
	else if (c_s == 'p')
		print_num = p_pointer(va_arg(vlist, void *), &flag);
	else if (c_s == 'd' || c_s == 'i')
		print_num = p_decimal(va_arg(vlist, int), &flag);
	else if (c_s == 'u')
		print_num = p_unsigned(va_arg(vlist, unsigned int), &flag);
	else if (c_s == 'x' || c_s == 'X')
		print_num = p_hex(va_arg(vlist, unsigned int), c_s, &flag);
	else if (c_s == '%')
		print_num = write(1, "%", 1);
	if (flag)
		return (-1);
	return (print_num);
}

int	ft_printf(const char *format, ...)
{
	va_list	vlist;
	int		plen;
	int		temp;

	plen = 0;
	va_start(vlist, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			temp = p_conversion_specifier(vlist, *(format));
		}
		else
			temp = p_char(*format);
		if (temp == -1)
			return (-1);
		plen += temp;
		format++;
	}
	va_end(vlist);
	return (plen);
}
