/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 22:48:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setting_window(t_mlx *mlx, t_file *info)
{
	setting_img_data(mlx, info);
	mlx->wptr = mlx_new_window(mlx->mptr, HORIZONTAL, VERTICAL, "fdf");
	if (!mlx->wptr)
		print_error("mlx_new_window", 0, info);
	mlx->img = mlx_new_image(mlx->mptr, HORIZONTAL, VERTICAL);
	mlx->addr = mlx_get_data_addr(mlx->img, \
	&mlx->bpp, &mlx->len, &mlx->endian);
}

void	setting_img_data(t_mlx *mlx, t_file *info)
{
	mlx->bpp = 24;
	mlx->len = info->limit_col;
	mlx->endian = 0;
}

void	adjusting_screen(t_map **map, t_file *info)
{
	int		m_row;
	int		m_col;

	m_row = info->limit_row - 1;
	m_col = info->limit_col - 1;
	get_height(map, info);
	info->width = fabs(map[m_row][m_col].y - map[0][0].y);
	info->height = fabs(info->max_height - info->min_height);
	if (info->width < info->height)
		extend_screen(map, info, VERTICAL / (int)info->height);
	else
		extend_screen(map, info, HORIZONTAL / (int)info->width);
	get_height(map, info);
	locate_mid(map, info);
}

void	extend_screen(t_map **map, t_file *info, int mtp)
{
	int		row;
	int		col;

	if (info->limit_col < 100 || info->limit_row < 100)
		mtp /= 1.5;
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x *= mtp;
			map[row][col].y *= mtp;
			++col;
		}
		++row;
	}
}
