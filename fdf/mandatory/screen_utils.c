/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 17:02:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setting_window(t_mlx *mlx, t_file *info)
{
	mlx->wptr = mlx_new_window(mlx->mptr, info->width, info->height, "fdf");
	if (!mlx->wptr)
		print_error("mlx_new_window", 0, info);
	input_key(mlx->wptr);
}

void	adjusting_screen(t_map **map, t_file *info)
{
	int		row;
	int		col;
	int		mtp_x;
	int		mtp_y;

	mtp_x = 2;
	while (info->height * mtp_x < VERTICAL)
		mtp_x++;
	info->height *= (mtp_x - 1);
	mtp_y = 2;
	while (info->width * mtp_y < HORIZONTAL)
		mtp_y++;
	info->width *= (mtp_y - 1);
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x *= ((mtp_x - 1) * 3 / 4);
			map[row][col].y *= ((mtp_y - 1) * 3 / 4);
			++col;
		}
		++row;
	}
}
