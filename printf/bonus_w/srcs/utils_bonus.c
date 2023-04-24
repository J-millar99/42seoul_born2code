/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:33:35 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 16:43:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	ft_unbrlen_base(unsigned long n, t_uint base)
{
	size_t	nb_len;

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

void	ft_putunbr_base_fd(t_print *ps, unsigned long n, char *b, int fd)
{
	t_uint	base_len;
	int		temp;

	temp = 0;
	if (ps->wflag == -1)
		return ;
	base_len = ft_strlen(b);
	if (n >= base_len)
	{
		ft_putunbr_base_fd(ps, n / base_len, b, fd);
		ft_putunbr_base_fd(ps, n % base_len, b, fd);
	}
	if (n < base_len)
		temp = ft_putchar_fd(b[n], fd);
	if (temp == -1)
		ps->wflag = -1;
}

void	ft_putnbr_base_fd(t_print *ps, long n, char *base, int fd)
{
	t_uint	base_len;
	long	temp;

	temp = 0;
	if (ps->wflag == -1)
		return ;
	base_len = ft_strlen(base);
	if (n < 0)
		n = -n;
	if (n >= base_len)
	{
		ft_putnbr_base_fd(ps, n / base_len, base, fd);
		ft_putnbr_base_fd(ps, n % base_len, base, fd);
	}
	if (n >= 0 && n < base_len)
		temp = ft_putchar_fd(base[n], fd);
	if (temp == -1)
		ps->wflag = -1;
}

int	flag_unbr_len_base(t_print *ps, t_uint nb, t_uint base)
{
	int	nb_len;

	if (nb == 0 && ps->dot)
		nb_len = 1;
	nb_len = ft_unbrlen_base(nb, base);
	return (nb_len);
}

int	flag_nbr_len_base(int nb, int base)
{
	int		nb_len;

	nb_len = 1;
	while (nb / base)
	{
		nb = nb / base;
		nb_len++;
	}
	return (nb_len);
}
