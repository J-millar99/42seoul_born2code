/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:06:54 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/15 18:06:54 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
	%기호 다음 기호(플래그)를 확인한다
	플래그가 맞다면 print_Info구조체의 변수를 조작하고
	숫자라면 '.'을 만나기 전과 후로 width와 precision을 조정한다

	37: '0'은 '.', '-'에 의해 무시되므로, '.'와 '-'가 모두 0일때만 조정한다
		"0-", "-0" 주의
	41: ' '은 '+'에 의해 무시되므로 '+'가 0일때 동작할 수 있도록 한다
		" +", "+ " 주의
*/

const char	*set_flags(t_print *print_Info, const char *f)
{
	init_flags(print_Info);
	while (*f && !ft_strchr((TYPE), *f))
	{
		if (*f == '#')
			print_Info->hash = 1;
		else if (*f == '.')
			print_Info->dot = 1;
		else if (*f == '-')
			print_Info->minus = 1;
		else if (*f == '0' && !print_Info->dot && !print_Info->minus)
			print_Info->zero = 1;
		else if (*f == '+')
			print_Info->plus = 1;
		else if (*f == ' ' && !print_Info->plus)
			print_Info->space = 1;
		else if (ft_isdigit(*f))
			f = handle_width(print_Info, f);
		f++;
	}
	if (*f && (!check_type(print_Info, *f)))
		print_Info->plen += ft_putchar_fd(*f, 1);
	return (f);
}

void	init_flags(t_print *print_Info)
{
	print_Info->space = 0;
	print_Info->hash = 0;
	print_Info->minus = 0;
	print_Info->plus = 0;
	print_Info->zero = 0;
	print_Info->dot = 0;
	print_Info->precision = 0;
	print_Info->width = 0;
}

/*
	f는 숫자가 시작하는 지점 문자열
	'.'를 만나기 전이면 width, 만난 후면 precision처리
*/

const char	*handle_width(t_print *print_Info, const char *f)
{
	if (print_Info->dot)
		print_Info->precision = ft_atoi(f);
	else
		print_Info->width = ft_atoi(f);
	while (ft_isdigit(*(f + 1)))
		f++;
	return (f);
}

/*
	90, 92: 무시되는 플래그 재초기화
*/

int	check_type(t_print *print_Info, const char sp)
{
	static t_type_ptr	type_arr[9] = {type_c, type_s, type_p, type_d,
		type_i, type_u, type_lower_x, type_upper_x, type_percent};
	int					idx;

	if (print_Info->zero && (print_Info->dot || print_Info->minus))
		print_Info->zero = 0;
	if (print_Info->space && print_Info->plus)
		print_Info->space = 0;
	if (ft_strchr(TYPE, sp))
	{
		idx = type_num(TYPE, sp);
		if (!(sp == 'x' || sp == 'X'))
			print_Info->hash = 0;
		type_arr[idx](print_Info);
		return (1);
	}
	else
		return (0);
}

int	type_num(char *type, char sp)
{
	char	*type_idx;

	type_idx = ft_strchr(type, sp);
	return (type_idx - type);
}
