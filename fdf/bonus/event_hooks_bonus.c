/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:20:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 19:37:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	event_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->wptr, 2, 0, &input_key, mlx);
	mlx_hook(mlx->wptr, 17, 0, &close_window, mlx);
	return (1);
}

int	input_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mptr, mlx->wptr);
		free_map(mlx->map, mlx->info);
		exit(0);
	}
	else if (keycode == ERASE)
		mlx_clear_window(mlx->mptr, mlx->wptr);
	else if (123 <= keycode && keycode <= 126)
		move_key(mlx, keycode);
	else if (keycode == ZOOMIN || keycode == ZOOMOUT)
		size_key(mlx, keycode);
	else if (keycode == X_AXIS || keycode == Y_AXIS || keycode == Z_AXIS)
		rotate_key(mlx, keycode);
	else if (keycode == PJ_A || keycode == PJ_B)
		projection_key(mlx, keycode);
	else if (keycode == R_COLOR || keycode == W_COLOR || keycode == INIT_COLOR)
		random_color(mlx, keycode);
	check_limit(mlx);
	return (1);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mptr, mlx->wptr);
	free_map(mlx->map, mlx->info);
	exit(0);
	return (1);
}
