/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enviornment_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 18:26:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void			set_forks_on_table(t_sys *system);
static const char	*fork_name(t_uint i);

void	set_environment(t_sys *system)
{
	set_forks_on_table(system);
	system->status = ACTIVATE;
}

static void	set_forks_on_table(t_sys *system)
{
	t_uint	i;
	char	*file_name;

	i = 0;
	system->sema_forks = malloc(sizeof(sem_t) * system->num_of_philo);
	if (!system->sema_forks)
		error("sema_forks malloc error");
	while (i < system->num_of_philo)
	{
		file_name = fork_name(i);
		system->sema_forks[i] = sem_open(file_name, O_CREAT, 0644, 1);
		free_str(file_name);
		i++;
	}
}

static const char	*fork_name(t_uint i)
{
	char	num;
	char	*rstr;

	num = (char)(('9' - '0' + 1) + i);
	rstr = ft_strjoin("./cabinet/fork_", i);
	if (!rstr)
		error("ft_strjoin error");
	return (rstr);
}