/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enviornment_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:10:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_environment(t_sys *system)
{
	const char	*temp;
	t_uint		i;

	i = 0;
	system->forks = ft_sem_open("forks", system->num_of_philo);
	system->message = ft_sem_open("message", 1);
	system->philo_status = (sem_t **)ft_malloc(sizeof(sem_t *), \
	system->num_of_philo);
	while (i < system->num_of_philo)
	{
		temp = ft_itoa(i + 1);
		system->philo_status[i] = ft_sem_open(temp, 1);
		free_str((char *)temp);
		i++;
	}
	system->pids = (pid_t *)ft_malloc(sizeof(pid_t), system->num_of_philo);
}
