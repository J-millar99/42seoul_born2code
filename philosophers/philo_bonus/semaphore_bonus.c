/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:27:41 by millar            #+#    #+#             */
/*   Updated: 2023/11/25 02:27:07 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t   *ft_sem_open(const char *sem_name, int num_of_access_data)
{
    sem_t   *ret;

	ret = sem_open(sem_name, O_CREAT, 0644, num_of_access_data);
	if (ret == SEM_FAILED)
		error("sem_open error");
    return (ret);
}

void	ft_sem_wait(sem_t *semaphore)
{
	if (sem_wait(semaphore) == -1)
		error("sem_wait error");
}

void	ft_sem_post(sem_t *semaphore)
{
	if (sem_post(semaphore) == -1)
		error("sem_post error");
}
