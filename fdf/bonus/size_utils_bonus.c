/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:37:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 12:35:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_size(t_mlx *mlx, int keycode)
{
	// void	*img;
	// char	*img_addr;
	// img = mlx_new_image(mlx->mptr, HOR, VER);
	// img_addr = mlx_get_data_addr(img, NULL, NULL, NULL);
	if (keycode == PLUS && mlx->w_max != W_MAX)
		extend_screen(mlx);
	else if (keycode == MINUS && mlx->w_max != W_MIN)
		contract_screen(mlx);
}

void	extend_screen(t_mlx *mlx)
{
	int		r;
	int		c;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx);
	r = 0;
	while (r < mlx->info->limit_row)
	{
		c = 0;
		while (c < mlx->info->limit_col)
		{
			mlx->map[r][c].x *= 2;
			mlx->map[r][c].y *= 2;
			if (fabs(mlx->map[r][c].x) >= VER / 2 \
			|| fabs(mlx->map[r][c].y) >= HOR / 2)
			{	
				mlx->w_max = W_MAX;
				mlx->w_min = 0;
			}
			++c;
		}
		++r;
	}
	locate_mid(mlx->map, mlx->info);
	plotting(mlx, mlx->map, mlx->info);
}

void	contract_screen(t_mlx *mlx)
{
	int		r;
	int		c;

	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_zero(mlx);
	r = 0;
	while (r < mlx->info->limit_row)
	{
		c = 0;
		while (c < mlx->info->limit_col)
		{
			mlx->map[r][c].x /= 2;
			mlx->map[r][c].y /= 2;
			if (fabs(mlx->map[r][c].x) < 2 || fabs(mlx->map[r][c].y) < 2)
			{	
				mlx->w_max = 0;
				mlx->w_min = W_MIN;
			}
			++c;
		}
		++r;
	}
	locate_mid(mlx->map, mlx->info);
	plotting(mlx, mlx->map, mlx->info);
}
