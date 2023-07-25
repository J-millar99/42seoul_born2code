/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 10:19:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_image(void *mlx_ptr, void *win_ptr)
{
	void	*image_ptr;
	char	*image_data;
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 8;
	size_line = 8;
	endian = 1;
	image_ptr = mlx_new_image(mlx_ptr, 800, 600);
	if (!image_ptr)
		print_error("mlx_new_image", 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, 0);
	image_data = mlx_get_data_addr(image_ptr, &bpp, &size_line, &endian);
	if (!image_data)
		print_error("mlx_get_data_addr", 0);
}
