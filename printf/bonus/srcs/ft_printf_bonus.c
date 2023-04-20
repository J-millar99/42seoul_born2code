/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/20 17:12:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	not_sp(const char *f)
{
	int		i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			while (ft_strchr(FLAG, f[i]))
				i++;
			if (!ft_strchr(TYPE, f[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_format(const char *f)
{
	if (!f)
		return (0);
	if (!not_sp(f))
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_print	ps;

	va_start(ps.vlist, format);
	if (!check_format(format))
		return (-1);
	ps.plen = 0;
	while (*format)
	{
		if (*format == '%')
			format = set_flags(&ps, format + 1);
		else
			ps.plen += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ps.vlist);
	return (ps.plen);
}
