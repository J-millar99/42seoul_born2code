/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:32:25 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 13:00:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_unsigned_len(unsigned int num)
{
	int		cnt;

	cnt = 1;
	while (num / 10)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

void	print_unsigned_num(unsigned int num, int *flag)
{
	int		temp;

	if (*flag)
		return ;
	temp = 0;
	if (num >= 10)
	{
		print_unsigned_num(num / 10, flag);
		print_unsigned_num(num % 10, flag);
	}
	else
		temp = write(1, &"0123456789"[num % 10], 1);
	if (temp == -1)
		*flag = 1;
}

int	p_unsigned(unsigned int num, int *flag)
{
	unsigned int	num_len;

	num_len = 0;
	num_len += check_unsigned_len(num);
	print_unsigned_num(num, flag);
	return (num_len);
}
