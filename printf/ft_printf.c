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

void	p_char(va_list *vlist)
{
	int		c;

	c = va_arg(*vlist, char *);
	write(1, c, 3);
}

void	print_format(va_list *vlist, const char **format)
{
	if (**format == 's')
		p_char(&(*vlist));
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

int main()
{
	char	*ptr = "123";
	ft_printf("%s", ptr);
	return 0;
}
