/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:54:03 by millar            #+#    #+#             */
/*   Updated: 2023/11/09 16:59:08 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    message(char *notice, t_philo *philo)
{
    unsigned int    time;

    pthread_mutex_lock(&philo->message);
    time = get_time(philo->info) - philo->info->start_time;
    if (!ft_strcmp("is dead", notice) && !philo->info->death)
    {
        printf("%u %d %s\n", time, philo->idx, notice);
        philo->info->death = 1;
    }
    if (!philo->info->death)
        printf("%u %d %s\n", time, philo->idx, notice);
    pthread_mutex_unlock(&philo->message);
}

void    *supervisor(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *) ptr;
    while (philo->info->death == 0)
    {
        if (get_time(philo->info) >= philo->lifespan && philo->eating == 0)
            message("is dead", philo);
        if (philo->num_of_meals == philo->info->num_of_must_meals)
        {
            pthread_mutex_lock(&philo->message);
            philo->info->survive++;
            pthread_mutex_unlock(&philo->message);
        }
    }
    return ((void *) 0);
}

void    *behave(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *) ptr;
    philo->lifespan = get_time(philo->info) + philo->info->time_to_die;
    if (pthread_create(&philo->pthread_supervisor, NULL, &supervisor, philo))
        return ((void *) 1);
    while (!philo->info->death)
    {
        eating(philo);
        message("is thinking", philo);
    }
    if (pthread_join(philo->pthread_supervisor, NULL))
        return ((void *) 1);
    return ((void *) 0);
}