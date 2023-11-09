/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/09 15:14:03 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (make_system_info(line_arr, system));
}
