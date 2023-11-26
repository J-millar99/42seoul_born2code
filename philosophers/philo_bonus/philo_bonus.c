/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 01:33:37 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	enter(t_sys *system);
static void	simulate(t_sys *system);
static void	process_exit(t_sys *system, t_uint except);

int	main(int argc, char *argv[])
{
	t_sys	*system;

	system = (t_sys *)ft_malloc(sizeof(t_sys), 1);
	check_input(argc, argv + 1, system);
	set_environment(system);
	simulate(system);
	ft_exit(system);
	return (0);
}

static void	enter(t_sys *system)
{
	t_uint		i;
	pid_t		philo;

	i = 0;
	ft_sem_wait(system->sema_start);
	system->time = get_time();
	while (i < system->num_of_philo)
	{
		philo = fork();
		if (philo == 0)
		{
			system->num_of_philo -= i;
			routine(system);
			exit(0);
		}
		else
			system->pids[i] = philo;
		i++;
	}
	ft_sem_post(system->sema_start);
}

static void	simulate(t_sys *system)
{
	t_uint	i;
	int		status;
	int		cnt;

	enter(system);
	while (1)
	{
		cnt = 0;
		i = 0;
		while (i < system->num_of_philo)
		{
			pid_t temp = waitpid(system->pids[i], &status, WNOHANG);
			if (temp > 0)
			{
				if (WIFSIGNALED(status))
				{
					process_exit(system, i);
					return ;
				}
				else if (WIFEXITED(status))
					cnt++;
			}
			i++;
		}
		if ((t_uint) cnt == system->num_of_philo)
		{
			process_exit(system, cnt + 1);
			return ;
		}	
	}
}

static void	process_exit(t_sys *system, t_uint except)
{
	t_uint i;

	i = 0;
	while (i < system->num_of_philo)
	{
		if (i == except)
		{
			i++;
			continue;
		}
		kill(system->pids[i], SIGTERM);
		i++;
	}
}