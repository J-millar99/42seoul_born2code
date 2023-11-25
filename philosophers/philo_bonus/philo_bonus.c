/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/25 02:34:07 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_sys	*system;

	system = (t_sys *)ft_malloc(sizeof(t_sys), 1);
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
	system->philos = (pid_t *)ft_malloc(sizeof(pid_t), system->num_of_philo);
	ft_sem_wait(system->sema_start);
	while (i < system->num_of_philo)
	{
		philo = fork();
		if (philo == 0)
		{
			system->num_of_philo -= i;
			if (pthread_create(&thread, NULL, routine, system))
				error("pthread_create error");
			pthread_join(thread, NULL);
			exit(0);
		}
		else
			system->philos[i] = philo;
		i++;
	}
}

void	simulate(t_sys *system)
{
	enter(system);
	ft_sem_post(system->sema_start);
	monitoring() // 죽음 추적 -> 프로세스 종료 회수;
}
