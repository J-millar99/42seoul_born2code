/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:39:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 12:42:10 by jaehyji          ###   ########.fr       */
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

	initializing_map(&map);
	map.x = (row - (info->limit_row / 2)) * info->p_x;
	map.y = (col - (info->limit_col / 2)) * info->p_y;
	ft_atoi_z(&map, arr[col]);
	return (map);
}
