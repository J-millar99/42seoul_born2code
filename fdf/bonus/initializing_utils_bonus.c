/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:36:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 19:20:26 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	initializing_fileinfo(t_file *info, char *filename)
{
	info->limit_row = 0;
	info->limit_col = 0;
	info->fd = 0;
	info->filename = filename;
}

void	initializing_coordinates_data(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->color = 0;
}

void	setting_mlx(t_flag *lflag, t_mlx *mlx, t_map **map, t_file *info)
{
	mlx->map = map;
	mlx->info = info;
	lflag->up_max = 0;
	lflag->down_max = 0;
	lflag->right_max = 0;
	lflag->left_max = 0;
	mlx->lflag = lflag;
}

void	init_color(t_mlx *mlx)
{
	int		row;
	int		col;

	locate_zero(mlx->map, mlx->info);
	mlx_clear_window(mlx->mptr, mlx->wptr);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].color = mlx->map[row][col].init_color;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
