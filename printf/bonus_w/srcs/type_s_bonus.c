/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:47:27 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 13:58:37 by jaehyji          ###   ########.fr       */
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
	if (ps->wflag == -1)
		return ;
	type_s_print(ps, s, slen);
}

void	type_s_print(t_print *ps, char *s, int slen)
{
	if (ps->dot)
	{
		ps->wflag = ft_putsubstr(s, slen);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	else
	{
		ps->wflag = ft_putstr_fd(s, 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	if (ps->width && ps->minus)
		padding(ps, slen);
}

int	ft_putsubstr(char *s, int slen)
{
	return (write(1, s, slen));
}
