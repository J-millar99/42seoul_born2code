/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:25:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/01 16:00:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_rotate(t_mlx *mlx, int keycode)
{
	locate_zero(mlx);
	if (keycode == X)
		rotate_x(mlx);
	else if (keycode == Y)
		rotate_y(mlx);
	else if (keycode == Z)
		rotate_z(mlx);
	locate_mid(mlx->map, mlx->info);
	plotting(mlx, mlx->map, mlx->info);
}

void	rotate_x(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	theta = M_PI / 6;
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
}

void	rotate_y(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	theta = M_PI / 6;
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
}

void	rotate_z(t_mlx *mlx)
{
	int		row;
	int		col;
	double	theta;

	theta = M_PI / 6;
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
}
