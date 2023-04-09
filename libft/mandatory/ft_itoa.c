/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:57:45 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 01:57:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_sign_cnt(int n, int *sign, int *cnt)
{
	*cnt = 0;
	if (n >= 0)
		*sign = 1;
	else
		*sign = -1;
	if (n == 0)
	{
		*cnt = 1;
		return ;
	}
	while (n != 0)
	{
		n /= 10;
		(*cnt)++;
	}
}

static char	*get_memory(int cnt, int sign)
{
	char	*ptr;

	if (sign > 0)
	{
		ptr = malloc(sizeof(char) * (cnt + 1));
		if (!ptr)
			return (NULL);
		ptr[cnt] = '\0';
	}
	else
	{
		ptr = malloc(sizeof(char) * (cnt + 2));
		if (!ptr)
			return (NULL);
		ptr[0] = '-';
		ptr[cnt + 1] = '\0';
	}
	return (ptr);
}

static void	arr_num(char *ptr, int n, int cnt)
{
	char	num[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		num[i] = i + '0';
		i++;
	}
	num[i] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		if (n > 0)
			ptr[cnt - 1] = num[n % 10];
		else
			ptr[cnt] = num[n % 10 * -1];
		cnt--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		cnt;
	char	*numstr;

	get_sign_cnt(n, &sign, &cnt);
	numstr = get_memory(cnt, sign);
	if (numstr == NULL)
		return (NULL);
	arr_num(numstr, n, cnt);
	return (numstr);
}
