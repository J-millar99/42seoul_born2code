/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enviornment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/10 11:11:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	enter(t_sys *system)
{
	unsigned int	idx;

	system->philos = malloc(sizeof(t_philo) * system->num_of_philo);
	if (!system->philos)
		return (0);
	idx = 0;
	while (idx < system->num_of_philo)
	{
		system->philos[idx].info = system;
		system->philos[idx].idx = idx + 1;
		system->philos[idx].num_of_meals = 0;
		system->philos[idx].status = 0;
		system->philos[idx].lifespan = system->time_to_die;
		system->philos[idx].eating = 0;
		pthread_mutex_init(&system->philos[idx].message, NULL);
		idx++;
	}
	return (1);
}

static int	set_forks_on_table(t_sys *system)
{
	unsigned int	idx;

	system->forks = malloc(sizeof(pthread_mutex_t) * system->num_of_philo);
	if (!system->forks)
		return (0);
	idx = 0;
	while (idx < system->num_of_philo)
		pthread_mutex_init(&system->forks[idx++], NULL);
	system->philos[0].r_fork = &system->forks[0];
	system->philos[0].l_fork = &system->forks[system->num_of_philo - 1];
	idx = 1;
	while (idx < system->num_of_philo)
	{
		system->philos[idx].l_fork = &system->forks[idx];
		system->philos[idx].r_fork = &system->forks[idx - 1];
		idx++;
	}
	return (1);
}

int	set_environment(t_sys *system)
{
	if (!enter(system))
		return (0);
	if (!set_forks_on_table(system))
		return (0);
	return (1);
}
