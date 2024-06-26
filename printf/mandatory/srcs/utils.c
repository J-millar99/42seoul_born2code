/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:52:22 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:18:34 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_unsigned_int_len(unsigned int num, int baselen)
{
	int		cnt;

	cnt = 1;
	while (num / baselen)
	{
		num /= baselen;
		cnt++;
	}
	return (cnt);
}

int	check_unsigned_long_len(unsigned long n)
{
	int		cnt;

	cnt = 1;
	while (n / 16)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

int	check_int_len(int n)
{
	int		cnt;

	cnt = 1;
	while (n / 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

size_t	ft_strlen(const char *s)
{
	int		idx;
	ssize_t	len;

	idx = 0;
	len = 0;
	while (s[idx++] != 0)
		++len;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
