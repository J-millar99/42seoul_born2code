/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:15:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 20:25:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_map **map, t_file *info)
{
	int		row;
	int		col;
	double	theta;

	row = 0;
	info->width = (int)sqrt(pow(info->limit_row, 2) + pow(info->limit_col, 2));
	info->height = info->width;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			if (info->height < fabs(map[row][col].z))
				info->height = fabs(map[row][col].z);
			theta = M_PI / 4;
			rotate_std_z(&map[row][col], theta);
			theta = M_PI / 3;
			rotate_std_y(&map[row][col], theta);
			++col;
		}
		++row;
	}
}

void	rotate_std_y(t_map *map, double theta)
{
	double	std_x;
	double	std_y;
	double	std_z;

	std_x = map->x;
	std_y = map->y;
	std_z = map->z;
	map->x = std_x * cos(theta) - std_z * sin(theta);
	map->y = std_y;
	map->z = (std_x * sin(theta)) * -1 + std_z * cos(theta);
}

void	rotate_std_z(t_map *map, double theta)
{
	double	std_x;
	double	std_y;
	double	std_z;

	std_x = map->x;
	std_y = map->y;
	std_z = map->z;
	map->x = std_x * cos(theta) - std_y * sin(theta);
	map->y = std_x * sin(theta) + std_y * cos(theta);
	map->z = std_z;
}
