/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/07 17:48:38 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isolated_philosopher(t_sys *sys)
{
	sys->start_time = get_time();
	if (pthread_create(&sys->philos[0].pthread_behavior, NULL, \
	&behave, &sys->philos[0]));
		return (error());
	// pthread_detach(sys->philos[0].pthread_behavior);
	pthread_join(sys->philos[0].pthread_behavior, NULL);
	return (0);
}

