/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:15:11 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:15:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo);
static void	sleeping(t_philo *philo);
static void	thinking(t_philo *philo);

void	*routine(void *ptr)
{
	t_philo	*philo;
	int		numofmustmeals;

	philo = (t_philo *)ptr;
	numofmustmeals = philo->system->num_of_must_meals;
	while (numofmustmeals == -1 || philo->num_of_meals != numofmustmeals)
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

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	message("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	message("has taken a fork", philo);
	message("is eating", philo);
	philo->lifespan = get_time();
	philo->num_of_meals++;
	ft_usleep(philo->system->time_to_eat, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	ft_usleep(philo->system->time_to_sleep, philo);
}

static void	thinking(t_philo *philo)
{
	message("is thinking", philo);
	usleep(200);
}
