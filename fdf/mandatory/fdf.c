/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/27 10:06:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
	1. 중앙정렬.
	2. 올바른 회전.
	3. 들어온 인자에 따른, 다른 해상도.
	4. 직선사이 거리 벌리기.
	5. MAKEFILE, NORM, LEAKS확인.
*/

// void	f(void)
// {
// 	system("leaks myfdf");
// }

int	main(int ac, char *av[])
{
	void	*mlx_ptr;
	t_file	info;

	// atexit(f);
	if (ac == 2)
	{
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			print_error("mlx_init", 0, &info);
		initializing_fileinfo(&info, av[1]);
		checking_map(&info);
		make_map(mlx_ptr, &info);
	}
	else
		print_error("Argument count must be only two", 0, &info);
	return (0);
}
