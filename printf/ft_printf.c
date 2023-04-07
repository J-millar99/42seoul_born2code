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

int	check_conversion_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'\
	|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

size_t	read_format(const char **format)
{
	if (!**format)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (**format == '%')
		(*format)++;
	else
		return (-1);
	if (!check_conversion_specifier(**format))
		return (-1);
	return (2);
}

void	print_format(va_list *vlist, const char **format)
{
	if (**format == 'c')
		p_char(&(*vlist));
	else if (**format == 's')
		p_str(&(*vlist));
	else if (**format == 'p')
		p_pointer(&(*vlist));
	else if (**format == 'd' || **format == 'i')
		p_decimal(&(*vlist));
	else if (**format == 'u')
		p_unsigned(&(*vlist));
	else if (**format == 'x')
		p_hex(&(*vlist));
	else if (**format == 'X')
		p_capital_hex(&(*vlist));
	else if (**format == '%')
		p_percent_sign(&(*vlist));
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	vlist;
	size_t	plen;

	if (!format)
		return (-1);
	va_start(vlist, format);
	plen = read_format(&format);
	print_format(&vlist, &format);
	va_end(vlist);
	return (plen);
}
