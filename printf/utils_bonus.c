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

int	unbrlen_base(unsigned long n, unsigned int base)
{
	int		result;

	if (base <= 1)
		return (0);
	result = 1;
	while (n / base)
	{
		n /= base;
		result++;
	}
	return (result);
}

ssize_t	nbrlen_base(long n, unsigned int base)
{
	ssize_t			nb_len;

	if (!base)
		return (0);
	nb_len = 1;
	if (n < 0)
	{
		nb_len += 1;
		n = -n;
	}
	while (n / base)
	{
		n = n / base;
		nb_len++;
	}
	return (nb_len);
}

void	ft_putptr_base_fd(unsigned long n, char *base, int fd)
{
	unsigned int	blen;

	if (!base)
		return ;
	blen = ft_strlen(base);
	if (blen < 2)
		return ;
	if (n >= blen)
	{
		ft_putptr_base_fd(n / blen, base, fd);
		ft_putptr_base_fd(n % blen, base, fd);
	}
	if (n < blen)
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
