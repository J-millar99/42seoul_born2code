/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:59:12 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 01:59:12 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_cnt(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	numarr[11];
	int		cnt;

	cnt = check_cnt(n);
	if (n < 0)
		write(fd, "-", 1);
	numarr[cnt] = '\0';
	while (cnt > 0)
	{
		if (n >= 0)
			numarr[cnt - 1] = (n % 10) + '0';
		else
			numarr[cnt - 1] = (n % 10 * -1) + '0';
		n /= 10;
		cnt--;
	}
	while (numarr[cnt])
	{
		write(fd, &numarr[cnt], 1);
		cnt++;
	}
}
