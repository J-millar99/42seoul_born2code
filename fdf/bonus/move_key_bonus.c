/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:54:39 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 12:06:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_key(t_mlx *mlx, int keycode)
{
	if (keycode == UP && !mlx->lflag->up_max)
		move_up(mlx);
	else if (keycode == DOWN && !mlx->lflag->down_max)
		move_down(mlx);
	else if (keycode == RIGHT && !mlx->lflag->right_max)
		move_right(mlx);
	else if (keycode == LEFT && !mlx->lflag->left_max)
		move_left(mlx);
}

void	move_up(t_mlx *mlx)
{
	int		row;
	int		col;

	locate_zero(mlx->map, mlx->info);
	mlx_clear_window(mlx->mptr, mlx->wptr);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].x -= 15;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	move_down(t_mlx *mlx)
{
	int		row;
	int		col;

	locate_zero(mlx->map, mlx->info);
	mlx_clear_window(mlx->mptr, mlx->wptr);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].x += 15;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	move_right(t_mlx *mlx)
{
	int		row;
	int		col;

	locate_zero(mlx->map, mlx->info);
	mlx_clear_window(mlx->mptr, mlx->wptr);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].y += 15;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	move_left(t_mlx *mlx)
{
	int		row;
	int		col;

	locate_zero(mlx->map, mlx->info);
	mlx_clear_window(mlx->mptr, mlx->wptr);
	row = 0;
	while (row < mlx->info->limit_row)
	{
		col = 0;
		while (col < mlx->info->limit_col)
		{
			mlx->map[row][col].y -= 15;
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
