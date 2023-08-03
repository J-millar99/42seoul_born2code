/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:46:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 12:57:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_projection(t_mlx *mlx, int keycode)
{
	if (keycode == PJ_A)
	{
		orthographic_projection(mlx->map, mlx->info);
		locate_mid(mlx->map, mlx->info);
		plotting(mlx, mlx->map, mlx->info);
	}
	else if (keycode == PJ_B)
	{
		isometric_projection(mlx->map, mlx->info);
		locate_mid(mlx->map, mlx->info);
		plotting(mlx, mlx->map, mlx->info);
	}
	else if (keycode == PJ_C)
	{
		oblique_projection(mlx->map, mlx->info);
		locate_mid(mlx->map, mlx->info);
		plotting(mlx, mlx->map, mlx->info);
	}
}

void	orthographic_projection(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].z = 0;
			++col;
		}
		++row;
	}
}

void	isometric_projection(t_map **map, t_file *info)
{
	int		row;
	int		col;
	double	theta;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			theta = M_PI / 4;
			rotate_std_z(&map[row][col], theta);
			theta = M_PI / 3;
			rotate_std_y(&map[row][col], theta);
			++col;
		}
		++row;
	}
}

void	oblique_projection(t_map **map, t_file *info)
{
	int		row;
	int		col;
	double	theta;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			theta = M_PI / 6;
			rotate_std_x(&map[row][col], theta);
			++col;
		}
		++row;
	}
}
