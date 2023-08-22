/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/22 15:11:39 by jaehyji          ###   ########.fr       */
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
	t_id	*table;

	// atexit(f);
	memset(system.info, 0, sizeof(system.info));
	if (!check_input(argc, argv + 1, system.info))
		return (printf("Input Error\n"));
	if (!enter(&table, system.info[0]))
		return (printf("Enter_Error\n"));
	simulate(system, table);
	lstclear(&table);
	return (0);
}
