/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:08:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/02 06:09:42 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_sys	system;
	t_id	*table;

	memset(system.info, 0, sizeof(system.info));
	if (!check_input(argc, argv + 1, system.info))
		return (write(2, "Input Error\n", 12));
	if (!enter(&table, system.info[0]))
		return (write(2, "Enter Error\n", 12));
	for (int i = 0; i < system.info[0]; i++)
	{
		printf("%d\n", table->idx);
		table = table->next;
	}
	// simulate(system, table);
	escape(table, system.info[0]);
	return (0);
}
