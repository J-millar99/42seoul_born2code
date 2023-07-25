/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 20:13:01 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_image(void *mlx_ptr, void *win_ptr, int *fd)
{
	void	*image_ptr;


	image_ptr = mlx_new_image(mlx_ptr, 800, 600);
	if (!image_ptr)
		print_error("mlx_new_image", 0, fd);
}
