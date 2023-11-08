/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:54:03 by millar            #+#    #+#             */
/*   Updated: 2023/11/07 17:53:20 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int    get_time()
{
    struct timeval  time_val;

    if (gettimeofday(&time_val, NULL) == -1)
        return (error());
    return (time_val.tv_sec / 1000);
}

void    *behave(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *) ptr;
    philo->
}