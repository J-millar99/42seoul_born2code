/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:21:37 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 19:24:50 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	random_color(t_mlx *mlx, int keycode)
{
	if (keycode == INIT_COLOR)
		init_color(mlx);
	else if (keycode == R_COLOR)
		random_rgb(mlx);
	else if (keycode == W_COLOR)
		random_microwave(mlx);
}

unsigned int	generate_random_rgb(void)
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

unsigned int	generate_random_microwave(void)
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


void	random_rgb(t_mlx *mlx)
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
			mlx->map[row][col].color = generate_random_rgb();
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}

void	random_microwave(t_mlx *mlx)
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
			mlx->map[row][col].color = generate_random_microwave();
			++col;
		}
		++row;
	}
	draw(mlx, mlx->map, mlx->info);
}
