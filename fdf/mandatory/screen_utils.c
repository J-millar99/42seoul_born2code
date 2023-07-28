/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 17:55:32 by jaehyji          ###   ########.fr       */
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

	while (info->height * info->mtp_x < VERTICAL)
		info->mtp_x++;
	info->height *= (info->mtp_x - 1);
	while (info->width * info->mtp_y < HORIZONTAL)
		info->mtp_y++;
	info->width *= (info->mtp_y - 1);
	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			map[row][col].x *= ((info->mtp_x - 1) * 9 / 10);
			map[row][col].y *= ((info->mtp_y - 1) * 9 / 10);
			++col;
		}
		++row;
	}
}
