/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:39:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 08:57:58 by jaehyji          ###   ########.fr       */
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

	initializing_coordinates_data(&map);
	map.x = row - (info->limit_row / 2);
	map.y = col - (info->limit_col / 2);
	ft_atoi_z(&map, arr[col]);
	return (map);
}

void	draw(t_mlx *mlx, t_map **map, t_file *info)
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
				draw_line(mlx, map[row][col], map[row][col + 1]);
			if (row < info->limit_row - 1)
				draw_line(mlx, map[row][col], map[row + 1][col]);
			++col;
		}
		++row;
	}
	mlx_put_image_to_window(mlx->mptr, mlx->wptr, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mptr, mlx->img);
}

void	draw_line(t_mlx *mlx, t_map p, t_map q)
{
	double	inc;
	double	xinc;
	double	yinc;
	int		i;
	char	*dst;

	if (fabs(q.x - p.x) > fabs(q.y - p.y))
		inc = fabs(q.x - p.x);
	else
		inc = fabs(q.y - p.y);
	xinc = (q.x - p.x) / inc;
	yinc = (q.y - p.y) / inc;
	i = 0;
	while (i <= inc)
	{
		if (p.x < VERTICAL && p.y < HORIZONTAL)
		{
			dst = mlx->addr + ((int)p.x * mlx->len + (int)p.y * mlx->bpp / 8);
			*(int *)dst = p.color;
		}
		p.x += xinc;
		p.y += yinc;
		i++;
	}
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
			map[row][col].x += (VERTICAL - info->max_height);
			map[row][col].y += (HORIZONTAL / 2);
			++col;
		}
		++row;
	}
}
