/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 12:42:01 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	input_key(t_mlx *mlx)
{
	mlx_key_hook(mlx->wptr, &on_key_press, mlx);
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(1);
	else if ((PJ_A <= keycode && keycode <= PJ_C) && !mlx->on_img)
	{
		mlx->on_img = 1;
		key_projection(mlx, keycode);
	}
	else if ((keycode == PLUS || keycode == MINUS) && mlx->on_img)
		key_size(mlx, keycode);
	else if ((keycode == X || keycode == Y || keycode == Z) && mlx->on_img)
	{
		mlx_clear_window(mlx->mptr, mlx->wptr);
		key_rotate(mlx, keycode);
	}
	else if (keycode == ERASE && mlx->on_img)
	{
		mlx->on_img = 0;
		initializing_coordinates(mlx->map, mlx->info);
		mlx_clear_window(mlx->mptr, mlx->wptr);
	}
	return (0);
}
