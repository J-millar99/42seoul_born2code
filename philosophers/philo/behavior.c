/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:06 by millar            #+#    #+#             */
/*   Updated: 2023/11/23 23:42:07 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    message("has taken a fork", philo);
    pthread_mutex_lock(philo->r_fork);
    message("has taken a fork", philo);
    message("is eating", philo);
    philo->lifespan = get_time();
    ft_usleep(philo->system->time_to_eat, philo);
    philo->num_of_meals++;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void    sleeping(t_philo *philo)
{
    message("is sleeping", philo);
    ft_usleep(philo->system->time_to_sleep, philo);
}

void    thinking(t_philo *philo)
{
    message("is thinking", philo);
    usleep(100);
}