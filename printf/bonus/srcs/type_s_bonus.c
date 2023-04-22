/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:47:27 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/20 17:16:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
		s = "(null)";
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
