/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:33:35 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/16 16:33:35 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_unbrlen_base(unsigned long n, unsigned int base)
{
	size_t			nb_len;

	if (!base)
		return (0);
	nb_len = 1;
	while (n / base)
	{
		n = n / base;
		nb_len++;
	}
	return (nb_len);
}

void	ft_put_unbr_base_fd(unsigned long n, char *base, int fd)
{
	unsigned int	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_put_unbr_base_fd(n / base_len, base, fd);
		ft_put_unbr_base_fd(n % base_len, base, fd);
	}
	if (n < base_len)
		ft_putchar_fd(base[n], fd);
}

void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	unsigned int	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= base_len)
	{
		ft_putnbr_base_fd(n / base_len, base, fd);
		ft_putnbr_base_fd(n % base_len, base, fd);
	}
	if (n >= 0 && n < base_len)
		ft_putchar_fd(base[n], fd);
}

static int	flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base)
{
	int	nb_len;

	if (nb == 0 && ps->dot)
		nb_len = 1;
	nb_len = ft_unbrlen_base(nb, base);
	return (nb_len);
}

void	unbr_left_padding(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if (ps->hash && ps->width && ps->dot && nb > 0 && !ps->minus)
		ps->width -= 2;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && !ps->precision && !ps->minus))
	{
		if ((ps->dot && ps->precision > nb_len))
			ps->width -= ps->precision - nb_len;
		if (ps->width && ps->hash && nb && !ps->dot)
			nb_len += 2;
		padding(ps, nb_len);
	}
}
