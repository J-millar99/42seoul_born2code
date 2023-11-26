/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/27 01:33:00 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*init_philo(t_sys *system);
static void		eating(t_philo *philo);
static void		sleeping(t_philo *philo);
static void		thinking(t_philo *philo);


void	grave(t_philo *philo)
{
	const char	*temp;

	temp = ft_itoa(philo->idx);
	ft_sem_close(philo->status);
	ft_sem_unlink(temp);
	free_str((char *)temp);
	free(philo);
}

void	message(char *notice, t_philo *philo)
{
	long long	time;

	ft_sem_wait(philo->system->sema_message);
	if (!waitpid(0, NULL, WNOHANG))
		return ;
	time = get_time() - philo->system->time;
	printf("%lld %u %s\n", time, philo->idx, notice);
	if (!ft_strcmp(notice, "died"))
	{
		kill(0, SIGTERM);
		usleep(1000);
		ft_sem_post(philo->system->sema_message);
		return ;
	}
	ft_sem_post(philo->system->sema_message);
}

void	*check_philo_status(void *ptr)
{
	t_sys		*system;
	long long	time;

	system = (t_sys *)ptr;
	while (!waitpid(0, NULL, WNOHANG))
	{
		ft_sem_wait(system->philo->status);
		time = get_time() - system->philo->lifespan;
		if (time > system->time_to_die)
		{
			message("died", system->philo);
			break;
		}
		ft_sem_post(system->philo->status);
		usleep(500);
	}
	grave(system->philo);
	return (NULL);
}

void	routine(t_sys *system)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = init_philo(system);
	system->philo = philo;
	if (pthread_create(&thread, NULL, check_philo_status, system))
		error("pthread_create error");
	pthread_detach(thread);
	while (!system->num_of_must_meals || philo->num_of_meals != system->num_of_must_meals)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

static void	eating(t_philo *philo)
{
	ft_sem_wait(philo->system->sema_forks);
	message("has taken a fork", philo);
	ft_sem_wait(philo->system->sema_forks);
	message("has taken a fork", philo);
	message("is eating", philo);
	ft_usleep(philo->system->time_to_eat);
	ft_sem_wait(philo->status);
	philo->lifespan = get_time();
	ft_sem_post(philo->status);
	philo->num_of_meals++;
	ft_sem_post(philo->system->sema_forks);
	ft_sem_post(philo->system->sema_forks);
}

static void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	ft_usleep(philo->system->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	message("is thinking", philo);
}

static t_philo	*init_philo(t_sys *system)
{
	t_philo		*philo;
	const char	*temp;

	philo = (t_philo *)ft_malloc(sizeof(t_philo), 1);
	philo->system = system;
	philo->idx = system->num_of_philo;
	philo->num_of_meals = 0;
	temp = ft_itoa(system->num_of_philo);
	philo->status = ft_sem_open(temp, 1);
	free_str((char *)temp);
	ft_sem_wait(system->sema_start);
	ft_sem_post(system->sema_start);
	philo->lifespan = get_time();
	if (philo->idx % 2 == 0)
		usleep(500);
	return (philo);
}