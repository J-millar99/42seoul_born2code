/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_key_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:40:17 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 12:06:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	projection_key(t_mlx *mlx, int keycode)
{
	if (keycode == PJ_A)
		oblique_projection(mlx, mlx->map, mlx->info);
	else if (keycode == PJ_B)
		isometric_projection(mlx, mlx->map, mlx->info);
}

void	oblique_projection(t_mlx *mlx, t_map **map, t_file *info)
{
	int		row;
	int		col;

	initializing_coordinates(map, info);
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
	draw(mlx, mlx->map, mlx->info);
}

void	isometric_projection(t_mlx *mlx, t_map **map, t_file *info)
{
	int		row;
	int		col;

	initializing_coordinates(map, info);
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			rotate_std_z(&map[row][col], M_PI / 4);
			rotate_std_y(&map[row][col], M_PI / 3);
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	initializing_coordinates(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x = map[row][col].init_x;
			map[row][col].y = map[row][col].init_y;
			map[row][col].z = map[row][col].init_z;
			++col;
		}
		++row;
	}
}
