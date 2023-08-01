/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/01 15:09:54 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_map(t_mlx *mlx, t_file *info)
{
	t_map	**map;

	info->fd = open(info->filename, O_RDONLY, 0644);
	map = initial_map(info);
	isometric_projection(map, info);
	locate_mid(map, info);
	mlx->wptr = mlx_new_window(mlx->mptr, HOR, VER, "fdf");
	if (!mlx->wptr)
		print_error("mlx_new_window", 0, info);
	plotting(mlx, map, info);
	setting_mlx(mlx, map, info);
	input_key(mlx);
	mlx_loop(mlx->mptr);
	free_map(map, info);
	mlx_destroy_window(mlx->mptr, mlx->wptr);
}

t_map	**initial_map(t_file *info)
{
	t_map	**map;
	char	**coordinate_array;
	int		row;
	int		col;

	map = (t_map **)malloc(sizeof(t_map *) * info->limit_row);
	if (!map)
		print_error("malloc", 1, info);
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		map[row] = (t_map *)malloc(sizeof(t_map) * info->limit_col);
		if (!map[row])
			print_error("malloc", 1, info);
		coordinate_array = one_coordinate_line(info);
		while (col < info->limit_col)
		{
			map[row][col] = coordinate(row, col, coordinate_array, info);
			++col;
		}
		free_split(coordinate_array);
		++row;
	}
	return (map);
}

void	plotting(t_mlx *mlx, t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = 0;
	while (row < info->limit_row - 1)
	{
		col = 0;
		while (col < info->limit_col - 1)
		{
			if (col < info->limit_col - 1)
				line_put(mlx, map[row][col], map[row][col + 1]);
			if (row < info->limit_row - 1)
				line_put(mlx, map[row][col], map[row + 1][col]);
			++col;
		}
		++row;
	}
}

void	line_put(t_mlx *mlx, t_map map1, t_map map2)
{
	double	inc;
	double	xinc;
	double	yinc;
	int		i;

	if (fabs(map2.x - map1.x) > fabs(map2.y - map1.y))
		inc = fabs(map2.x - map1.x);
	else
		inc = fabs(map2.y - map1.y);
	xinc = (map2.x - map1.x) / inc;
	yinc = (map2.y - map1.y) / inc;
	i = 0;
	while (i <= inc)
	{
		mlx_pixel_put(mlx->mptr, mlx->wptr, map1.y, map1.x, map1.color);
		map1.x += xinc;
		map1.y += yinc;
		i++;
	}
}

void	setting_mlx(t_mlx *mlx, t_map **map, t_file *info)
{
	mlx->info = info;
	mlx->map = map;
	mlx->w_min = 0;
	mlx->w_max = 0;
}
