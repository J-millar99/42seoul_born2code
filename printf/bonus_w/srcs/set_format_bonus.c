/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:06:54 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 13:08:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
	ps->wflag = 0;
}

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

void	check_type(t_print *ps, const char sp)
{
	static t_type_ptr	type_arr[9] = {type_c, type_s, type_p, type_d,
		type_i, type_u, type_lx, type_ux, type_percent};
	int					idx;

	if (ps->zero && (ps->dot || ps->minus))
		ps->zero = 0;
	if (ps->space && ps->plus)
		ps->space = 0;
	idx = type_num(TYPE, sp);
	if (idx != 6 && idx != 7)
		ps->hash = 0;
	type_arr[idx](ps);
}

int	type_num(char *type, char sp)
{
	char	*type_idx;

	type_idx = ft_strchr(type, sp);
	return (type_idx - type);
}
