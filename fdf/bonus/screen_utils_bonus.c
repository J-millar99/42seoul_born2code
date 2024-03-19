/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 14:58:32 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	setting_window(t_mlx *mlx, t_file *info)
{
	setting_img_data(mlx, info);
	mlx->wptr = mlx_new_window(mlx->mptr, HORIZONTAL, VERTICAL, "fdf");
	if (!mlx->wptr)
		print_error("mlx_new_window", 0, info);
}

void	setting_img_data(t_mlx *mlx, t_file *info)
{
	mlx->bpp = 24;
	mlx->len = info->limit_col;
	mlx->endian = 0;
}

void	setting_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mptr, HORIZONTAL, VERTICAL);
	mlx->addr = mlx_get_data_addr(mlx->img, \
	&mlx->bpp, &mlx->len, &mlx->endian);
}
