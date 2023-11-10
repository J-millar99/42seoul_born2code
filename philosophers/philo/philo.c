/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/10 17:34:47 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (system->num_of_philo == 1)
		return (isolated_philosopher(system));
	else
		return (simulate(system));
	return (0);
}
