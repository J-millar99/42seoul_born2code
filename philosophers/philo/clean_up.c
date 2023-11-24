/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 11:45:19 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destory_system(t_sys *system)
{
	if (system->forks)
		free(system->forks);
	if (system->philos)
		free(system->philos);
	if (system)
		free(system);
}

void	ft_exit(t_sys *system)
{
	t_uint	idx;

	idx = 0;
	while (idx < system->num_of_philo)
		pthread_mutex_destroy(&system->forks[idx++]);
	pthread_mutex_destroy(&system->message);
	pthread_mutex_destroy(&system->end);
	destory_system(system);
}

void	free_str(char *str)
{
	if (!str)
		return ;
	free(str);
}

void	free_arr(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		str[idx] = NULL;
		idx++;
	}
	free(str);
}

int	ft_error(char *error_string, t_sys *system)
{
	printf("%s is error\n", error_string);
	if (system)
		ft_exit(system);
	return (1);
}
