/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:10:52 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 17:05:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_max(t_flag *flag)
{
	if (flag->up_max || flag->down_max || flag->right_max || flag->left_max)
		return (1);
	return (0);
}

void	size_key(t_mlx *mlx, int keycode)
{
	int		max;

	max = is_max(mlx->lflag);
	if (keycode == ZOOMIN && !max)
		zoomin_image(mlx);
	else if (keycode == ZOOMOUT)
		zoomout_image(mlx);
}

void	zoomin_image(t_mlx *mlx)
{
	int		row;
	int		col;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx->map, mlx->info);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].x *= 1.1;
			mlx->map[row][col].y *= 1.1;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	zoomout_image(t_mlx *mlx)
{
	int		row;
	int		col;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx->map, mlx->info);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].x /= 1.1;
			mlx->map[row][col].y /= 1.1;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
