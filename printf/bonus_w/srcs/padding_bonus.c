/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:33:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 15:37:52 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	padding(t_print *ps, int occupied_len)
{
	char	space;

	if (ps->wflag == -1)
		return ;
	ps->wflag = 0;
	space = ' ';
	if (ps->zero)
		space = '0';
	while (ps->width > occupied_len)
	{
		ps->wflag = ft_putchar_fd(space, 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
		occupied_len++;
	}
}

void	zero_padding(t_print *ps, int max, int min)
{
	while (max > min)
	{
		ps->wflag = ft_putchar_fd('0', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
		min++;
	}
}

void	nb_zero_padding(t_print *ps)
{
	if (ps->minus)
		return (nb_zero_minus_padding(ps));
	if (!ps->dot)
	{
		padding(ps, ps->precision + 1);
		if (ps->wflag == -1)
			return ;
		ps->wflag = ft_putchar_fd('0', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
	}
	else
		padding(ps, ps->precision);
}

void	nb_zero_minus_padding(t_print *ps)
{
	if (!ps->dot)
	{
		ps->wflag = ft_putchar_fd('0', 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
		padding(ps, ps->precision + 1);
	}
	else
		padding(ps, ps->precision);
}

void	sign_padding(t_print *ps, int occupied_len)
{
	char	space;
	int		tmp;

	tmp = ps->width;
	space = ' ';
	if (ps->zero)
		space = '0';
	if (ps->space || ps->plus)
		tmp--;
	while (tmp > occupied_len)
	{
		ps->wflag = ft_putchar_fd(space, 1);
		if (ps->wflag == -1)
			return ;
		ps->plen += ps->wflag;
		occupied_len++;
	}
}
