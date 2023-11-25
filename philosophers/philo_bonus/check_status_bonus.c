/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/25 03:01:41 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
