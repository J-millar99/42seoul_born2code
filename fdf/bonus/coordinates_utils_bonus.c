/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:39:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 12:12:49 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	**one_coordinate_line(t_file *info)
{
	char	*line;
	char	**coordinate_array;

	line = get_next_line(info->fd);
	coordinate_array = ft_split(line, ' ');
	if (!coordinate_array)
		print_error("ft_split", 1, info);
	free(line);
	return (coordinate_array);
}

t_map	coordinate(int row, int col, char **arr, t_file *info)
{
	t_map	map;

	initializing_coordinates_data(&map);
	map.std_x = row;
	map.std_y = col;
	map.x = row - (info->limit_row / 2);
	map.y = col - (info->limit_col / 2);
	ft_atoi_z(&map, arr[col]);
	map.std_z = map.z;
	return (map);
}

void	locate_mid(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x += (VER / 2);
			map[row][col].y += (HOR / 2);
			++col;
		}
		++row;
	}
}

void	locate_zero(t_mlx *mlx)
{
	int		row;
	int		col;

	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].x -= (VER / 2);
			mlx->map[row][col].y -= (HOR / 2);
			++col;
		}
		++row;
	}
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
			map[row][col].x = row - (info->limit_row / 2);
			map[row][col].y = col - (info->limit_col / 2);
			map[row][col].z = map[row][col].std_z;
			++col;
		}
		++row;
	}
}
