/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:11:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
