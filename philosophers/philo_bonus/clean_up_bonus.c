/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/26 23:05:49 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_str(char *str)
{
	if (!str)
		return ;
	free(str);
}

void	free_arr(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		str[idx] = NULL;
		idx++;
	}
	free(str);
}

void	ft_exit(t_sys *system)
{
	ft_sem_close(system->sema_start);
	ft_sem_close(system->sema_forks);
	ft_sem_close(system->sema_message);
	ft_sem_unlink("./sema/button");
	ft_sem_unlink("./sema/forks");
	ft_sem_unlink("./sema/message");
	free(system->pids);
	free(system);
}