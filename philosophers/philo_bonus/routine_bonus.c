/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/24 20:16:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*init_philo(t_sys *system)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error("philo malloc error");
	philo->system = system;
	philo->idx = system->num_of_philo;
	philo->num_of_meals = 0;
	system->sema_forks[system->num_of_philo];
	system->seam_forks[system->num_of_philo - 1];
	philo->lifespan = get_time();
	return (philo);
}

void	*routine(void *ptr)
{
	t_sys	*system;
	t_philo	*philo;

	system = (t_sys *)ptr;
	philo = init_philo(system);
	while (!system->num_of_must_meals || philo->num_of_meals != system->num_of_must_meals)
	{
		if (!check_status(philo))
			break ;
		eating(philo);
		if (!check_status(philo))
			break ;
		sleeping(philo);
		if (!check_status(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	message("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	message("has taken a fork", philo);
	message("is eating", philo);
	ft_usleep(philo->system->time_to_eat, philo);
	philo->lifespan = get_time();
	philo->num_of_meals++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	ft_usleep(philo->system->time_to_sleep, philo);
}

void	thinking(t_philo *philo)
{
	message("is thinking", philo);
	usleep(200);
}
