/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/26 15:12:11 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_image(void *mlx_ptr, void *win_ptr, t_info *info)
{
	void	*image_ptr;


	image_ptr = mlx_new_image(mlx_ptr, 800, 600);
	if (!image_ptr)
		print_error("mlx_new_image", 0, info);
	f(mlx_ptr, win_ptr);
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}
