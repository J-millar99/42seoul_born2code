/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/18 21:16:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	t_sys	system;

	// atexit(f);
	memset(system.input_arr, 0, sizeof(system.input_arr));
	if (!check_input(argc, argv + 1, system.input_arr))
		return (printf("Input Error\n"));
	enter();
	sit();
	eat();
	psleep();
	think();
}
