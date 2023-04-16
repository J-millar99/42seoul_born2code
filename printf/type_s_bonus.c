/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:47:27 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 15:47:27 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
	24: s가 널일때 "(null)"이 되고 precision보다 길이가 작으면 출력 자체가 되지않음
		precision은 애초에 0이기 때문에 '.'이 존재할 경우에만 조건판별
*/

void	type_ston(t_print *ps, char *null)
{
	int		slen;

	if (ps->dot && ps->precision < (int)ft_strlen(null))
		null = "\0";
	slen = ft_strlen(null);
	if (ps->minus)
	{
		ps->plen += ft_putstr_fd(null, 1);
		if (ps->width > slen)
			padding(ps, slen);
	}
	else
	{
		if (ps->width > slen)
			padding(ps, slen);
		ps->plen += ft_putstr_fd(null, 1);
	}
}

/*
	57: '.'가 존재할 때 precision은 문자열의 길이를 제한한다
	60, 70: '-'여부를 따져서 앞 혹은 뒤에 padding을 한다
	62: padding중 '.'만났다면 s를 일부분으로 바꿔 출력하고 free
*/

void	type_s(t_print	*ps)
{
	char	*s;
	int		slen;

	slen = 0;
	s = va_arg(ps->vlist, char *);
	if (!s)
		return (spec_ston(ps, "(null)"));
	if (ps->dot && (ps->precision < (int)ft_strlen(s)))
		slen = ps->precision;
	else
		slen = ft_strlen(s);
	if (ps->width && !ps->minus)
		padding(ps, slen);
	if (ps->dot)
	{
		s = ft_substr(s, 0, slen);
		ps->plen += ft_putstr_fd(s, 1);
		free(s);
	}
	else
		ps->plen += ft_putstr_fd(s, 1);
	if (ps->width && ps->minus)
		padding(ps, slen);
}
