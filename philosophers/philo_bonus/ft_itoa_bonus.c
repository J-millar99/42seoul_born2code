/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:08:22 by millar            #+#    #+#             */
/*   Updated: 2023/11/27 14:59:43 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_itoa_len(int n)
{
	size_t	len;

	len = 0;
	if (!n)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_itoa_len(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		error("ft_itoa malloc error");
	if (!n)
		ptr[0] = '0';
	i = 0;
	if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		ptr[len - i - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}
