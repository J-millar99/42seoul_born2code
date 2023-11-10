/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/10 12:55:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_atoll(const char *str)
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

static char	*make_str(int argc, char **argv)
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

static int	cnt_arr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
		idx++;
	return (idx);
}

static int	make_system_info(char **argv, t_sys *system)
{
	long long	num;

	num = ft_atoll(argv[0]);
	if (num == -1)
		return (0);
	system->num_of_philo = (unsigned int) num;
	num = ft_atoll(argv[1]);
	if (num == -1)
		return (0);
	system->time_to_die = (unsigned int) num;
	num = ft_atoll(argv[2]);
	if (num == -1)
		return (0);
	system->time_to_eat = (unsigned int) num;
	num = ft_atoll(argv[3]);
	if (num == -1)
		return (0);
	system->time_to_sleep = (unsigned int) num;
	num = ft_atoll(argv[4]);
	if (num == -1)
		return (0);
	system->num_of_must_meals = (unsigned int) num;
	system->death = 0;
	system->survive = 0;
	return (1);
}

int	check_input(int argc, char **argv, t_sys *system)
{
	int		cnt;
	char	*line;
	char	**line_arr;

	line = make_str(argc, argv);
	if (!line)
		return (0);
	line_arr = ft_split(line, ' ');
	free_str(line);
	if (!line_arr)
		return (0);
	cnt = cnt_arr(line_arr);
	if (cnt != 4 && cnt != 5)
		return (0);
	make_system_info(line_arr, system);
	free_arr(line_arr);
	return (1);
}
