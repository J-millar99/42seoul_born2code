/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:24 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 17:00:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	init_philo(t_sys *system)
{
	t_philo		philo;

	philo.system = system;
	philo.idx = system->num_of_philo;
	philo.num_of_meals = 0;
	philo.status = system->philo_status[philo.idx - 1];
	philo.lifespan = get_time();
	if (philo.idx % 2 == 0)
		ft_usleep(system->time_to_eat / 2, NULL);
	return (philo);
}

void	check_philo_status(t_philo *philo)
{
	long long	time;

	time = get_time() - philo->lifespan;
	if (time > philo->system->time_to_die)
	{
		message("died", philo);
		exit(1);
	}
}

void	message(char *notice, t_philo *philo)
{
	long long	time;

	ft_sem_wait(philo->system->message);
	time = get_time() - philo->system->time;
	printf("%lld %u %s\n", time, philo->idx, notice);
	if (!ft_strcmp(notice, "died"))
		return ;
	ft_sem_post(philo->system->message);
}
