/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:31:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/11 02:31:51 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '0' || c == '-' || c == '.'\
	|| c == '*')
		return (1);
	return (0);
}

int	is_format(const char *format)
{
	int			result;

	if (!check_flag_duplication(format))
		return (0);
	if (*format == ' ')
		result = space_flag(format++);
	else if (*format == '#')
		result = shop_flag(format++);
	else if (*format == '+')
		result = plus_flag(format++);
	else if (*format == '0')
		result = zero_flag(format++);
	else if (*format == '-')
		result = minus_flag(format++);
	else if (*format == '.')
		result = dot_flag(format++);
	else if (*format == '*')
		result = width_flag(format++);
	return (result);
}

int	p_conversion_specifier(va_list vlist, const char c_s)
{
	int	print_num;

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
	int		plen;
	int		i;

	i = 0;
	plen = 0;
	va_start(vlist, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (!is_format(format + i))
				return (0);
			else if (is_flag(format[i]))
				plen = check_flag(vlist, format[i], &i);
			else
				plen = p_conversion_specifier(vlist, format[i]);
		}
		else
			plen += p_char(format[i]);
		i++;
	}
	va_end(vlist);
	return (plen);
}
