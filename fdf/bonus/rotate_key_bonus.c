/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:42:02 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 16:49:43 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_key(t_mlx *mlx, int keycode)
{
	if (keycode == X_AXIS)
		rotate_x(mlx);
	else if (keycode == Y_AXIS)
		rotate_y(mlx);
	else if (keycode == Z_AXIS)
		rotate_z(mlx);
}

void	rotate_x(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx->map, mlx->info);
	theta = M_PI / 12;
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			rotate_std_x(&mlx->map[row][col], theta);
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	rotate_y(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx->map, mlx->info);
	theta = M_PI / 12;
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			rotate_std_y(&mlx->map[row][col], theta);
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	rotate_z(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx->map, mlx->info);
	theta = M_PI / 12;
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			rotate_std_z(&mlx->map[row][col], theta);
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
