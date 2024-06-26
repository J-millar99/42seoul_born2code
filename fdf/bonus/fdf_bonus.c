/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 12:05:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int ac, char *av[])
{
	t_file	info;
	t_mlx	mlx;

	if (ac == 2)
	{
		mlx.mptr = mlx_init();
		if (!mlx.mptr)
			print_error("mlx_init", 0, &info);
		initializing_fileinfo(&info, av[1]);
		checking_map_data(&info);
		make_map(&mlx, &info);
	}
	else
		print_error("Argument count must be only two", 0, &info);
	return (0);
}
