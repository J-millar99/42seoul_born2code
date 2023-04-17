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

#include "../includes/ft_printf_bonus.h"

/*
	%기호 다음 기호(플래그)를 확인한다
	플래그가 맞다면 ps구조체의 변수를 조작하고
	숫자라면 '.'을 만나기 전과 후로 width와 precision을 조정한다

	37: '0'은 '.', '-'에 의해 무시되므로, '.'와 '-'가 모두 0일때만 조정한다
		"0-", "-0" 주의
	41: ' '은 '+'에 의해 무시되므로 '+'가 0일때 동작할 수 있도록 한다
		" +", "+ " 주의
*/

const char	*set_flags(t_print *ps, const char *f)
{
	init_flags(ps);
	while (*f && !ft_strchr((TYPE), *f))
	{
		if (*f == '#')
			ps->hash = 1;
		else if (*f == '.')
			ps->dot = 1;
		else if (*f == '-')
			ps->minus = 1;
		else if (*f == '0' && !ps->dot && !ps->minus)
			ps->zero = 1;
		else if (*f == '+')
			ps->plus = 1;
		else if (*f == ' ' && !ps->plus)
			ps->space = 1;
		else if (ft_isdigit(*f))
			f = handle_width(ps, f);
		f++;
	}
	check_type(ps, *f);
	return (f);
}

void	init_flags(t_print *ps)
{
	ps->space = 0;
	ps->hash = 0;
	ps->minus = 0;
	ps->plus = 0;
	ps->zero = 0;
	ps->dot = 0;
	ps->precision = 0;
	ps->width = 0;
}

/*
	f는 숫자가 시작하는 지점 문자열
	'.'를 만나기 전이면 width, 만난 후면 precision처리
*/

const char	*handle_width(t_print *ps, const char *f)
{
	if (ps->dot)
		ps->precision = ft_atoi(f);
	else
		ps->width = ft_atoi(f);
	while (ft_isdigit(*(f + 1)))
		f++;
	return (f);
}

/*
	90, 92: 무시되는 플래그 재초기화
*/

void	check_type(t_print *ps, const char sp)
{
	static t_type_ptr	type_arr[9] = {type_c, type_s, type_p, type_d,
		type_i, type_u, type_lower_x, type_upper_x, type_percent};
	int					idx;

	if (ps->zero && (ps->dot || ps->minus))
		ps->zero = 0;
	if (ps->space && ps->plus)
		ps->space = 0;
	idx = type_num(TYPE, sp);
	type_arr[idx](ps);
}

int	type_num(char *type, char sp)
{
	char	*type_idx;

	type_idx = ft_strchr(type, sp);
	return (type_idx - type);
}
