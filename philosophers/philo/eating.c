/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/09 16:58:32 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    message("takes right fork", philo);
    pthread_mutex_lock(philo->l_fork);
    message("takes left fork", philo);
    philo->eating = 1;
    philo->lifespan = get_time(philo->info) + philo->info->time_to_die;
    philo->num_of_meals++;
    message("is eating", philo);
}

static void	drop_forks_go_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
    philo->eating = 0;
	message("is sleeping", philo);
}

void    eating(t_philo *philo)
{
    take_forks(philo);
    drop_forks_go_sleep(philo);
}