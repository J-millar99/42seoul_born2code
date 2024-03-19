/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:16:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:16:14 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(const char *sem_name, int num_of_access_data)
{
	sem_t	*ret;

	ft_sem_unlink(sem_name);
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

void	ft_sem_close(sem_t *semaphore)
{
	if (sem_close(semaphore) == -1)
		error("sem_close error");
}

void	ft_sem_unlink(const char *semaphore)
{
	sem_unlink(semaphore);
}
