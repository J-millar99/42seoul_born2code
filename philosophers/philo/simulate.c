/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 11:25:00 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// t_mutex	bang1;
// t_mutex bang2;

static void	*routine1(void *ptr);
static void	*routine2(void *ptr);

int	simulate(t_sys *sys)
{
	t_uint	i;
	sys->time = get_time();
	// pthread_mutex_init(&bang1, NULL);
	// pthread_mutex_init(&bang2, NULL);
	// pthread_mutex_lock(&bang1);
	i = 1;
	while (1)
	{
		if (pthread_create(&sys->philos[i - 1].thread, NULL, routine1, &sys->philos[i - 1]))
			return (ft_error("ptread_create", sys));
		i += 2;
		if (i > sys->num_of_philo)
			break ;
	}
	// pthread_mutex_unlock(&bang1);
	i = 2;
	// pthread_mutex_lock(&bang2);
	while (1)
	{
		if (pthread_create(&sys->philos[i - 1].thread, NULL, routine2, &sys->philos[i - 1]))
			return (ft_error("ptread_create", sys));
		i += 2;
		if (i > sys->num_of_philo)
			break ;
	}
	// pthread_mutex_unlock(&bang2);
	i = 0;
	while (i < sys->num_of_philo)
		pthread_join(sys->philos[i++].thread, NULL);
	ft_exit(sys);
	return (0);
}

static void	*routine1(void *ptr)
{
	t_philo	*philo;
	int		numofmustmeals;

	philo = (t_philo *)ptr;
	// pthread_mutex_lock(&bang1);
	// pthread_mutex_unlock(&bang1);
	philo->lifespan = get_time();
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

static void	*routine2(void *ptr)
{
	t_philo	*philo;
	int		numofmustmeals;

	philo = (t_philo *)ptr;
	// pthread_mutex_lock(&bang2);
	// pthread_mutex_unlock(&bang2);
	philo->lifespan = get_time();
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
