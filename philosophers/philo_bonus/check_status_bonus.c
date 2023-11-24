/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 16:44:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_status(t_philo *philo)
{
	if (check_system_status(philo->system) || check_philosopher_status(philo))
		return (0);
	return (1);
}

int	check_philosopher_status(t_philo *philo)
{
	long long	time;

	time = get_time() - philo->lifespan;
	if (time > philo->system->time_to_die)
	{
		message("died", philo);
		return (DEAD);
	}
	return (ALIVE);
}

int	check_system_status(t_sys *system)
{
	int	return_value;

	pthread_mutex_lock(&system->end);
	return_value = system->status;
	pthread_mutex_unlock(&system->end);
	return (return_value);
}
