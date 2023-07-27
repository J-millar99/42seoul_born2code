/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:39:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/27 10:04:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int		gap;

	initializing_map(&map);
	if (info->limit_row < VERTICAL / 2)
		map.x = sqrt(row * info->limit_row);
	else if (info->limit_row < VERTICAL / 4)
		map.x = row * pow(info->limit_row, 10);
	else
		map.x = row + info->limit_row;
	if (info->limit_col < HORIZONTAL / 2)
		map.y = sqrt(col * info->limit_col);
	else if (info->limit_col < HORIZONTAL / 4)
		map.y = col * pow(info->limit_col, 10);
	else
		map.y = col + info->limit_col;
	ft_atoi_z(&map, arr[col]);
	return (map);
}

void	locate_mid(t_map *map, t_file *info)
{
	int		mid_x;
	int		mid_y;

	mid_x = (VERTICAL / 2) - (info->limit_row / 2);
	map->x += mid_x;
	mid_y = (HORIZONTAL / 2) - (info->limit_col / 2);
	map->y += mid_y;
}
