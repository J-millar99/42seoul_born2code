/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 14:40:11 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjusting_screen(t_map **map, t_file *info)
{
	int		row;
	int		col;
	double	mtp_x;
	double	mtp_y;

	get_mtp(info);
	mtp_x = 0.8;
	mtp_y = 0.8;
	if (info->mtp_x == 2)
		mtp_x = 1.5;
	if (info->mtp_y == 2)
		mtp_y = 1.5;
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x *= ((info->mtp_x - 1) * mtp_x);
			map[row][col].y *= ((info->mtp_y - 1) * mtp_y);
			++col;
		}
		++row;
	}
	locate_mid(map, info);
}

void	setting_window(t_mlx *mlx, t_file *info)
{
	mlx->wptr = mlx_new_window(mlx->mptr, info->width, info->height, "fdf");
	if (!mlx->wptr)
		print_error("mlx_new_window", 0, info);
	mlx->img = mlx_new_image(mlx->mptr, info->width, info->height);
	mlx->addr = mlx_get_data_addr(mlx->img, \
	&mlx->bpp, &mlx->line_length, &mlx->endian);
}

void	get_mtp(t_file *info)
{
	while (info->height * info->mtp_x <= VERTICAL)
		info->mtp_x++;
	info->height *= (info->mtp_x - 1);
	while (info->width * info->mtp_y <= HORIZONTAL)
		info->mtp_y++;
	info->width *= (info->mtp_y - 1);
	if (info->mtp_x == 2)
		info->height = VERTICAL;
	if (info->mtp_y == 2)
		info->width = HORIZONTAL;
}
