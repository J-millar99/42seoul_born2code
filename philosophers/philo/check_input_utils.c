/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:47:16 by millar            #+#    #+#             */
/*   Updated: 2023/11/06 16:35:09 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoll(const char *str)
{
	long long	num;

	if (!str)
		return (0);
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > 9999999999)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	if (num > UINT_MAX)
		return (-1);
	return (num);
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
