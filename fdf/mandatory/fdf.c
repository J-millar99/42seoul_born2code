/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/26 15:10:27 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void f()
// {
// 	system("leaks myfdf");
// }

t_info	make_info(void)
{
	t_info	info;

	info.fd = 0;
	return (info);
}

int	main(int ac, char *av[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_info	*info;

	//atexit(f);
	if (ac == 2)
	{
		*info = make_info();
		check_map(av[1], info);
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			print_error("mlx_init", 0, info);
		win_ptr = mlx_new_window(mlx_ptr, 1280, 800, "fdf");
		if (!win_ptr)
			print_error("mlx_init", 0, info);
		input_key(mlx_ptr, win_ptr);
		set_image(mlx_ptr, win_ptr, info);
		mlx_loop(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
	}
	else
		print_error("Argument count must be only two", 0, info);
	return (0);
}
