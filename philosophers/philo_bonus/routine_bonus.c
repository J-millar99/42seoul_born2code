/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/27 17:00:05 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	init_philo(t_sys *system);
static void		eating(t_philo *philo);
static void		sleeping(t_philo *philo);
static void		thinking(t_philo *philo);

void	routine(t_sys *system)
{
	t_philo		philo;

	philo = init_philo(system);
	while (!system->num_of_must_meals || \
	philo.num_of_meals != system->num_of_must_meals)
	{
		check_philo_status(&philo);
		eating(&philo);
		check_philo_status(&philo);
		sleeping(&philo);
		check_philo_status(&philo);
		thinking(&philo);
	}
}

static void	eating(t_philo *philo)
{
	ft_sem_wait(philo->system->forks);
	message("has taken a fork", philo);
	ft_sem_wait(philo->system->forks);
	message("has taken a fork", philo);
	message("is eating", philo);
	ft_usleep(philo->system->time_to_eat, philo);
	philo->lifespan = get_time();
	philo->num_of_meals++;
	ft_sem_post(philo->system->forks);
	ft_sem_post(philo->system->forks);
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
