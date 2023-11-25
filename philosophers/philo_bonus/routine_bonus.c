/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/25 03:06:15 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*init_philo(t_sys *system);
static void	eating(t_philo *philo);
static void	sleeping(t_philo *philo);
static void	thinking(t_philo *philo);

void	message(char *notice, t_philo *philo)
{
	long long	time;
	ft_sem_wait(philo->system->sema_message);
	time = get_time() - philo->system->time;
	printf("%lld %u %s\n", time, philo->idx, notice);
	ft_sem_post(philo->system->sema_message);
}

void	*routine(void *ptr)
{
	t_sys	*system;
	t_philo	*philo;

	system = (t_sys *)ptr;
	philo = init_philo(system);
	while (!system->num_of_must_meals || philo->num_of_meals != system->num_of_must_meals)
	{
		if (!check_philosopher_status(philo))
			break ;
		eating(philo);
		if (!check_philosopher_status(philo))
			break ;
		sleeping(philo);
		if (!check_philosopher_status(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}

static void	eating(t_philo *philo)
{
	ft_sem_wait(philo->system->sema_forks);
	message("has taken a fork", philo);
	ft_sem_wait(philo->system->sema_forks);
	message("has taken a fork", philo);
	message("is eating", philo);
	ft_usleep(philo->system->time_to_eat, philo);
	philo->lifespan = get_time();
	philo->num_of_meals++;
	ft_sem_post(philo->system->sema_forks);
	ft_sem_post(philo->system->sema_forks);
}

static void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	ft_usleep(philo->system->time_to_sleep, philo);
}

static void	thinking(t_philo *philo)
{
	message("is thinking", philo);
}

static t_philo	*init_philo(t_sys *system)
{
	t_philo	*philo;

	philo = (t_philo *)ft_malloc(sizeof(t_philo), 1);
	philo->system = system;
	philo->idx = system->num_of_philo;
	philo->num_of_meals = 0;
	philo->status = ALIVE;
	ft_sem_wait(system->sema_start);
	ft_sem_post(system->sema_start);
	system->time = get_time();
	philo->lifespan = get_time();
	return (philo);
}