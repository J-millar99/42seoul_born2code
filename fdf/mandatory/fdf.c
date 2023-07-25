/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 20:10:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void f()
// {
// 	system("leaks myfdf");
// }

int	main(int ac, char *av[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;

	//atexit(f);
	if (ac == 2)
	{
		fd = 0;
		check_map(av[1], &fd);
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			print_error("mlx_init", 0, &fd);
		win_ptr = mlx_new_window(mlx_ptr, 800, 600, "fdf");
		if (!win_ptr)
			print_error("mlx_init", 0, &fd);
		input_key(mlx_ptr, win_ptr);
		set_image(mlx_ptr, win_ptr, &fd);
		mlx_loop(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
	}
	else
		print_error("Argument count must be only two", 0, &fd);
	return (0);
}
