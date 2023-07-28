/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 21:42:32 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	증감제한구간 설정.
	회전.
	다른 투영.
*/

void	input_key(t_mlx *mlx)
{
	mlx_key_hook(mlx->wptr, &on_key_press, mlx);
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 35 && mlx->w_max == 0)
		extend_screen(mlx);
	if (keycode == 46 && mlx->w_max > -3)
		contract_screen(mlx);
	return (0);
}

void	extend_screen(t_mlx *mlx)
{
	int		r;
	int		c;

	locate_zero(mlx);
	r = 0;
	while (r < mlx->info->limit_row)
	{
		c = 0;
		while (c < mlx->info->limit_col)
		{
			mlx->map[r][c].x *= 2;
			mlx->map[r][c].y *= 2;
			if (mlx->map[r][c].x >= VER / 2 || mlx->map[r][c].y >= HOR / 2)
				mlx->w_max += 1;
			++c;
		}
		++r;
	}
	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_mid(mlx->map, mlx->info);
	plotting(mlx, mlx->map, mlx->info);
}

void	contract_screen(t_mlx *mlx)
{
	int		r;
	int		c;

	locate_zero(mlx);
	r = 0;
	while (r < mlx->info->limit_row)
	{
		c = 0;
		while (c < mlx->info->limit_col)
		{
			mlx->map[r][c].x /= 2;
			mlx->map[r][c].y /= 2;
			++c;
		}
		++r;
	}
	mlx_clear_window(mlx->mptr, mlx->wptr);
	locate_mid(mlx->map, mlx->info);
	plotting(mlx, mlx->map, mlx->info);
	mlx->w_max -= 1;
}
