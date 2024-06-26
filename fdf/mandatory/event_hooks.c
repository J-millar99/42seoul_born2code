/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:20:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 11:39:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	event_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->wptr, 2, 0, &esc_key, mlx);
	mlx_hook(mlx->wptr, 17, 0, &close_window, mlx);
}

int	esc_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mptr, mlx->wptr);
		free_map(mlx->map, mlx->info);
		exit(0);
	}
	return (1);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mptr, mlx->wptr);
	free_map(mlx->map, mlx->info);
	exit(0);
	return (1);
}
