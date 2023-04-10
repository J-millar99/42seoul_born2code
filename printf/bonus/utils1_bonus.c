/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:33:56 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/11 02:33:56 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	shop_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'x' || *format == 'X')
		return (1);
	return (0);
}

int plus_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i')
		return (1);
	return (0);
}

int	zero_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i' || *format == 'x' || *format == 'X'\
	|| *format == 'u')
		return (1);
	return (0);
}

int minus_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'\
	|| *format == 'X' || *format == 'p' || *format == 'c' || *format == 's')
		return (1);
	return (0);
}

int dot_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'\
	|| *format == 'X' || *format == 'p' || *format == 's')
		return (1);
	return (0);
}
