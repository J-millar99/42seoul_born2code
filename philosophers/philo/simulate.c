/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:12:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/10 17:35:29 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isolated_philosopher(t_sys *sys)
{
	sys->start_time = get_time(sys);
	if (pthread_create(&sys->philos[0].pthread_behavior, NULL, \
	behave, &sys->philos[0]))
		return (ft_error("pthread_create_function", sys));
	pthread_detach(sys->philos[0].pthread_behavior);
	while (!sys->death)
		;
	ft_exit(sys);
	return (0);
}

int	simulate(t_sys *sys)
{
	sys->death = 1;
	return (0);
}
