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
	slen은 출력할 문자열의 문자갯수
	'.'는 출력할 문자열을 제한
*/

void	type_s(t_print *print_Info)
{
	char	*s;
	char	*sub_s;
	int		slen;

	s = va_arg(print_Info->vlist, char *);
	if (!s)
		s = "(NULL)";
	if (print_Info->dot && (print_Info->precision < (int)ft_strlen(s)))
		slen = print_Info->precision;
	else
		slen = ft_strlen(s);
	if (print_Info->width && !print_Info->minus)
		padding(print_Info, slen);
	if (print_Info->dot)
	{
		sub_s = ft_substr(s, 0, slen);
		print_Info->plen += ft_putstr_fd(sub_s, 1);
		free(sub_s);
	}
	else
		print_Info->plen += ft_putstr_fd(s, 1);
	if (print_Info->width && print_Info->minus)
		padding(print_Info, slen);
}