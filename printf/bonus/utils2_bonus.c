/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:34:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/11 02:34:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int check_flag_duplication(char *str) //숫자중복은 제외 ex)%2020d
{
	int		cnt;

	cnt = 0;
	while (*str != '%' || !*str)
	{
		if (!('0' <= *str && *str <= '9'))
			cnt += pass_flag(*str);
		if (cnt == 2)
			return (0);
		str++;
	}
	return (1);
}

int	pass_flag(char c)
{
	if (c == '.' || c == '-' || c == '+' || c == '#' || c == ' ')
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	space_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i')
		return (1);
	return (0);
}

int width_flag(const char *format)
{
	while (pass_flag(*format))
		format++;
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'\
	|| *format == 'X' || *format == 'p' || *format == 'c' || *format == 's')
		return (1);
	return (0);
}