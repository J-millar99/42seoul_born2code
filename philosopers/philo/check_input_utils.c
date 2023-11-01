/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:47:16 by millar            #+#    #+#             */
/*   Updated: 2023/11/02 05:12:15 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str)
		return (-1);
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		return (-1);
	return (num * sign);
}

char	*make_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	if (!*argv)
		return (NULL);
	str = ft_strdup(argv[0]);
	if (!str)
		return (NULL);
	i = 1;
	while (i < argc - 1)
	{
		tmp = str;
		str = ft_strspacejoin(str, argv[i]);
		if (!str)
		{
			free_str(tmp);
			return (NULL);
		}
		i++;
		free(tmp);
	}
	return (str);
}

int cnt_arr(char **arr)
{
    int     idx;

    idx = 0;
    while (arr[idx])
        idx++;
    return (idx);
}
