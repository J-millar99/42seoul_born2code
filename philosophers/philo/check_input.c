/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:20:01 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*make_str(int argc, char **argv);
static int	cnt_arr(char **arr);
static int	make_system_info2(char **argv, t_sys *system);
static int	make_system_info1(char **argv, t_sys *system);

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
	{
		free_arr(line_arr);
		return (0);
	}
	if (!make_system_info1(line_arr, system))
	{
		free_arr(line_arr);
		return (0);
	}
	return (1);
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

static int	make_system_info1(char **argv, t_sys *system)
{
	long long	num;

	num = ft_atoll(argv[0]);
	if (num == -1 || num == 0)
		return (0);
	system->num_of_philo = (t_uint) num;
	num = ft_atoll(argv[1]);
	if (num == -1 || num == 0)
		return (0);
	system->time_to_die = (t_uint) num;
	num = ft_atoll(argv[2]);
	if (num == -1 || num == 0)
		return (0);
	system->time_to_eat = (t_uint) num;
	num = ft_atoll(argv[3]);
	if (num == -1 || num == 0)
		return (0);
	system->time_to_sleep = (t_uint) num;
	return (make_system_info2(argv, system));
}

static int	make_system_info2(char **argv, t_sys *system)
{
	long long	num;

	num = ft_atoll(argv[4]);
	if (num == -1)
		return (0);
	if (num == 0)
		num = -1;
	system->num_of_must_meals = num;
	free_arr(argv);
	return (1);
}
