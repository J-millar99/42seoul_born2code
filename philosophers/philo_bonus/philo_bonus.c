/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 20:02:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_sys	*system;

	system = malloc(sizeof(t_sys));
	if (!system)
		error("system malloc error");
	check_input(argc, argv + 1, system);
	set_environment(system);
	simulate(system);
	return (0);
}

void	enter(t_sys *system)
{
	t_uint		i;
	pid_t		philo;
	pthread_t	thread;

	i = 0;
	system->philos = malloc(sizeof(pid_t) * system->num_of_philo);
	system->time = get_time();
	while (i < system->num_of_philo)
	{
		philo = fork();
		if (philo)
		{
			system->num_of_philo -= i;
			if (pthread_create(thread, NULL, routine, system))
				error("pthread_create error");
			pthread_join(thread, NULL);
			exit(0);
		}
		else
			system->philos[i] = philo;
	}
		
}

void	simulate(t_sys *ststem)
{
	enter(system);
}
