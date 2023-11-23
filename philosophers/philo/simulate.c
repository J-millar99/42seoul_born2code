/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/23 23:41:07 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *routine(void *ptr);

int	simulate(t_sys *sys)
{
    uint    i;

    i = 0;
    while (i < sys->num_of_philo)
    {
        if (pthread_create(&sys->philos[i].thread, NULL, routine, &sys->philos[i]))
            return (ft_error("ptread_create", sys));
        i++;
    }
    i = 0;
    while (i < sys->num_of_philo)
        pthread_join(sys->philos[i++].thread, NULL);
    ft_exit(sys);
    return (0);
}

static void    *routine(void *ptr)
{
    t_philo *philo;
    int      numofmustmeals;

    philo = (t_philo *)ptr;
    numofmustmeals = philo->system->num_of_must_meals;
    if (philo->idx % 2 == 0)
        ft_usleep(100, NULL);
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

int check_status(t_philo *philo)
{
    if (check_philosopher_status(philo) || check_system_status(philo->system))
        return (0);
    return (1);
}

int check_philosopher_status(t_philo *philo)
{
    long long    time;

    time = get_time() - philo->lifespan;
    if (time > philo->system->time_to_die)
    {
        message("died", philo);
        return (DEAD);
    }
    return (ALIVE);
}

int check_system_status(t_sys *system)
{
    int return_value;

    pthread_mutex_lock(&system->end);
    return_value = system->status;    
    pthread_mutex_unlock(&system->end);
    return (return_value);
}
