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

	map = initial_map(info);
	mlx->map = map;
	mlx->info = info;
	setting_window(mlx, info);
	isometric_projection(map, info);
	adjusting_screen(map, info);
	draw(mlx, map, info);
	event_hooks(mlx);
	mlx_loop(mlx->mptr);
	free_map(map, info);
	mlx_destroy_image(mlx->mptr, mlx->wptr);
	mlx_destroy_window(mlx->mptr, mlx->wptr);
}

t_map	**initial_map(t_file *info)
{
	t_map	**map;
	char	**coordinate_array;
	int		row;
	int		col;

	info->fd = open(info->filename, O_RDONLY, 0644);
	map = (t_map **)malloc(sizeof(t_map *) * info->limit_row);
	if (!map)
		print_error("malloc", 1, info);
	row = -1;
	while (row++ < info->limit_row - 1)
	{
		col = -1;
		map[row] = (t_map *)malloc(sizeof(t_map) * info->limit_col);
		if (!map[row])
			print_error("malloc", 1, info);
		coordinate_array = one_coordinate_line(info);
		while (col++ < info->limit_col - 1)
			map[row][col] = coordinate(row, col, coordinate_array, info);
		free_split(coordinate_array);
	}
	close(info->fd);
	return (map);
}
