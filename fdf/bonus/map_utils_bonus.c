/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 16:31:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_map(t_mlx *mlx, t_file *info)
{
	t_map	**map;
	t_flag	lflag;

	map = initial_map(info);
	setting_mlx(&lflag, mlx, map, info);
	setting_window(mlx, info);
	event_hooks(mlx);
	// mlx_loop_hook(mlx->mptr, &event_hooks, mlx);
	mlx_loop(mlx->mptr);
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

void	draw(t_mlx *mlx, t_map **map, t_file *info)
{
	int		row;
	int		col;

	locate_mid(map, info);
	setting_image(mlx);
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
