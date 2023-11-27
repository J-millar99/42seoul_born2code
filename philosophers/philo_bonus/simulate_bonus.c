/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:52:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 17:01:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	enter(t_sys *system);
static void	simulate(t_sys *system);
static void	process_exit(t_sys *system, int *except);
static void	monitoring(t_sys *system, int *idx);

void	simulate(t_sys *system)
{
	int		*idx;

	idx = (int *)ft_malloc(sizeof(int), system->num_of_philo);
	memset(idx, 0, sizeof(idx));
	if (system->num_of_philo == 1)
	{	
		printf("0 1 has taken a fork\n");
		printf("%u 1 died\n", system->time_to_die);
	}
	else
	{
		enter(system);
		monitoring(system, idx);
	}
}

static void	enter(t_sys *system)
{
	t_uint		i;
	pid_t		philo;

	i = 0;
	system->time = get_time();
	while (i < system->num_of_philo)
	{
		philo = fork();
		if (philo == 0)
		{
			system->num_of_philo = i + 1;
			routine(system);
			exit(0);
		}
		else
			system->pids[i] = philo;
		i++;
	}
}

static void	monitoring(t_sys *system, int *idx)
{
	t_uint			i;
	int				status;
	unsigned char	test;

	while (1)
	{
		i = 0;
		while (i < system->num_of_philo)
		{
			if (idx[i] == 0 && waitpid(system->pids[i], &status, WNOHANG))
			{
				test = WEXITSTATUS(status);
				idx[i] = 1;
				if (test == 1)
					return (process_exit(system, idx));
				if (test == 0)
					return (monitoring(system, idx));
			}
			i++;
		}
		if (check_all_process(system, idx))
			return ;
	}
}

static int	check_all_process(t_sys *system, int *idx)
{
	t_uint	i;

	i = 0;
	while (i < system->num_of_philo)
	{
		if (idx[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	process_exit(t_sys *system, int *except)
{
	t_uint	i;

	i = 0;
	while (i < system->num_of_philo)
	{
		if (except[i] == 1)
		{
			i++;
			continue ;
		}
		kill(system->pids[i], SIGTERM);
		i++;
	}
	i = 0;
	while (i < system->num_of_philo)
	{
		if (except[i] == 1)
		{
			i++;
			continue ;
		}
		waitpid(system->pids[i], NULL, 0);
		i++;
	}
}
