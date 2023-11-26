/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enviornment_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 01:08:07 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_environment(t_sys *system)
{
	system->sema_start = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_start = ft_sem_open("button", 1);
	system->sema_forks = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_forks = ft_sem_open("forks", system->num_of_philo);
	system->sema_message = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_message = ft_sem_open("message", 1);
	system->pids = ft_malloc(sizeof(pid_t), system->num_of_philo);
}
