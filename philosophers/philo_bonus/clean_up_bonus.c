/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 16:32:38 by jaehyji          ###   ########.fr       */
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
	t_uint		i;
	const char	*temp;

	i = 0;
	ft_sem_close(system->forks);
	ft_sem_close(system->message);
	ft_sem_unlink("forks");
	ft_sem_unlink("message");
	while (i < system->num_of_philo)
	{
		ft_sem_close(system->philo_status[i]);
		temp = ft_itoa(i + 1);
		ft_sem_unlink(temp);
		free_str((char *)temp);
		i++;
	}
	free(system->philo_status);
	free(system->pids);
	free(system);
}
