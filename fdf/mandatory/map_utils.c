/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 17:02:32 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_map(t_mlx *mlx, t_file *info)
{
	t_map	**map;

	info->fd = open(info->filename, O_RDONLY, 0644);
	map = initial_map(info);
	isometric_projection(map, info);
	adjusting_screen(map, info);
	locate_mid(map, info);
	setting_window(mlx, info);
	plotting(mlx, map, info);
	free_map(map, info);
	mlx_loop(mlx->mptr);
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
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			if (col < info->limit_col - 1)
				line_put(mlx, map[row][col], map[row][col + 1], info);
			if (row < info->limit_row - 1)
				line_put(mlx, map[row][col], map[row + 1][col], info);
			++col;
		}
		++row;
	}
}

void	line_put(t_mlx *mlx, t_map map1, t_map map2, t_file *info)
{
	double	dx;
	double	dy;
	double	inc;
	double	xinc;
	double	yinc;

	dx = map2.x - map1.x;
	dy = map2.y - map1.y;
	if (fabs(dx) > fabs(dy))
		inc = fabs(dx);
	else
		inc = fabs(dy);
	xinc = dx / inc;
	yinc = dy / inc;
	int	i = -1;
	while (i++ <= inc)
	{
		if (map1.x < info->height && map1.y < info->width)
			mlx_pixel_put(mlx->mptr, mlx->wptr, map1.y, map1.x, map1.color);
		map1.x += xinc;
		map1.y += yinc;
	}
}
