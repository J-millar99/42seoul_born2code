/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:43:31 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/15 17:43:31 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
	%가 존재하면 서식 지정자에 맞게 출력할 준비를 하고
	그렇지 않다면 문자열로 취급해 그대로 출력시킨다
	printf("%")는 아무것도 출력하지 않기 때문에
	*(format + 1)와 같이 확인해버리면 else 분기점에서 잘못 출력될 수 있다
	그래서 %기호가 발견되면 반드시 set_format에서 플래그 여부를 확인한다
*/

int	ft_printf(const char *format, ...)
{
	t_print	print_Info;
	
	va_start(print_Info.vlist, format);
	while (*format)
	{
		if (*format == '%' && (format + 1))
			format = set_flags(&print_Info, format + 1);
		else
			print_Info.plen += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(print_Info.vlist);
	return (print_Info.plen);
}