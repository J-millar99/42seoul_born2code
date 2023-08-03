/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 22:48:23 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_map(t_mlx *mlx, t_file *info)
{
	t_map	**map;

	info->fd = open(info->filename, O_RDONLY, 0644);
	map = initial_map(info);
	setting_window(mlx, info);
	isometric_projection(map, info);
	adjusting_screen(map, info);
	draw(mlx, map, info);
	mlx_put_image_to_window(mlx->mptr, mlx->wptr, mlx->img, 0, 0);
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
