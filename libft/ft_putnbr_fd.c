/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaji <jaji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 04:01:55 by jaji              #+#    #+#             */
/*   Updated: 2023/03/22 04:48:19 by jaji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_cnt(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		cnt = 1;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static int	tenpow(int cnt)
{
	if (cnt == 0)
		return (1);
	return (10 * tenpow(cnt - 1));
}

static void	lastzero(int n, int fd)
{
	if (n % 10 == 0)
		write(fd, "0", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		cnt;
	int		temp;

	temp = n;
	cnt = check_cnt(n);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	while (n)
	{
		if (n > 0)
			c = (n / tenpow(cnt - 1)) + '0';
		else
			c = ((n / tenpow(cnt - 1)) * -1) + '0';
		write(fd, &c, 1);
		n %= tenpow(cnt - 1);
		cnt--;
	}
	lastzero(temp, fd);
}
