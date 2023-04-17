/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/17 18:41:42 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

/*
	%가 존재하면 서식 지정자에 맞게 출력할 준비를 하고
	그렇지 않다면 문자열로 취급해 그대로 출력시킨다
	
	33:	printf("%")는 아무것도 출력하지 않기 때문에
		*(format + 1)와 같이 확인해버리면 else 분기점에서 잘못 출력될 수 있다
		그래서 %기호가 발견되면 반드시 set_format에서 플래그 여부를 확인한다
*/

int	check_format(const char *f)
{
	int		i;
	int		cnt;

	if (!f)
		return (0);
	while (f[i]) // %다음 널문자면 끝
	{
		if (f[i] == '%')
		{
			i++;
			if (f[i] == '\0')
				return (0);
		}
	}
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
	}
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
