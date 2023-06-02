/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:47:27 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 15:14:22 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
