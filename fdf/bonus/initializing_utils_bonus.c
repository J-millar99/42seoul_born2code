/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizing_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:02:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 12:10:10 by jaehyji          ###   ########.fr       */
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
	map->std_x = 0;
	map->std_y = 0;
	map->std_z = 0;
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->color = 0;
}

void	setting_mlx(t_mlx *mlx, t_map **map, t_file *info)
{
	mlx->info = info;
	mlx->map = map;
	mlx->w_min = 0;
	mlx->w_max = 0;
	mlx->on_img = 0;
}
