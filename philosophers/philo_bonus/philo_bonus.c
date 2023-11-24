/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/24 16:44:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_sys	*system;

	system = malloc(sizeof(t_sys));
	if (!system)
		return (0);
	if (!check_input(argc, argv + 1, system))
		return (write(2, "Input Error\n", 12));
	if (!set_environment(system))
		return (write(2, "Set Error\n", 12));
	return (simulate(system));
}

static int	threads(t_sys *sys, t_uint i)
{
	while (1)
	{
		if (pthread_create(&sys->philos[i - 1].thread, NULL, \
		routine, &sys->philos[i - 1]))
			return (0);
		i += 2;
		if (i > sys->num_of_philo)
			break ;
	}
	return (1);
}

int	simulate(t_sys *sys)
{
	t_uint	i;

	if (sys->num_of_philo == 1)
	{	
		printf("0 1 has taken a fork\n");
		printf("%u 1 died\n", sys->time_to_die);
	}
	else
	{
		sys->time = get_time();
		i = 1;
		if (!threads(sys, i))
			return (ft_error("ptread_create", sys));
		ft_usleep(sys->time_to_eat, NULL);
		i = 2;
		if (!threads(sys, i))
			return (ft_error("ptread_create", sys));
		i = 0;
		while (i < sys->num_of_philo)
			pthread_join(sys->philos[i++].thread, NULL);
	}
	ft_exit(sys);
	return (0);
}
