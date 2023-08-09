/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:21:37 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 12:06:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	random_color(t_mlx *mlx, int keycode)
{
	if (keycode == INIT_COLOR)
		init_color(mlx);
	else if (keycode == R_COLOR)
		random_time(mlx);
	else if (keycode == W_COLOR)
		random_clock(mlx);
}

unsigned int	generate_random_time(void)
{
	unsigned int	random_value;
	int				i;

	random_value = 0;
	i = 0;
	srand(time(NULL));
	while (i < 4)
	{
		random_value = (random_value << 8) | (rand() & 0xFF);
		i++;
	}
	return (random_value);
}

unsigned int	generate_random_clock(void)
{
	unsigned int	random_value;
	int				i;

	random_value = 0;
	i = 0;
	srand(clock());
	while (i < 4)
	{
		random_value = (random_value << 8) | (rand() & 0xFF);
		i++;
	}
	return (random_value);
}

void	random_time(t_mlx *mlx)
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
			mlx->map[row][col].color = generate_random_time();
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	random_clock(t_mlx *mlx)
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
			mlx->map[row][col].color = generate_random_clock();
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
