/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enviornment_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/25 02:49:59 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_environment(t_sys *system)
{
	system->sema_start = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_start = ft_sem_open("./sema/button", 1);
	system->sema_forks = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_forks = ft_sem_open("./sema/forks", system->num_of_philo);
	system->sema_message = (sem_t *)ft_malloc(sizeof(sem_t), 1);
	system->sema_message = ft_sem_open("./sema/message", 1);
	system->status = ACTIVATE;
}
