/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/09 16:40:03 by millar           ###   ########.fr       */
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
	// simulate(system);
	return (0);
}
