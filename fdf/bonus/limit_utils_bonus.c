/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:14:06 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 19:28:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	check_limit(t_mlx *mlx)
{
	mlx->lflag->up_max = up_limit(mlx->map, mlx->info);
	mlx->lflag->down_max = down_limit(mlx->map, mlx->info);
	mlx->lflag->right_max = right_limit(mlx->map, mlx->info);
	mlx->lflag->left_max = left_limit(mlx->map, mlx->info);
}

int	up_limit(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = -1;
	while (row++ < info->limit_row - 1)
	{
		col = -1;
		while (col++ < info->limit_col - 1)
		{
			if (map[row][col].x <= 10)
				return (1);
		}
	}
	return (0);
}

int	down_limit(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = -1;
	while (row++ < info->limit_row - 1)
	{
		col = -1;
		while (col++ < info->limit_col - 1)
		{
			if (map[row][col].x >= VERTICAL)
				return (1);
		}
	}
	return (0);
}

int	left_limit(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = -1;
	while (row++ < info->limit_row - 1)
	{
		col = -1;
		while (col++ < info->limit_col - 1)
		{
			if (map[row][col].y <= 10)
				return (1);
		}
	}
	return (0);
}

int	right_limit(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = -1;
	while (row++ < info->limit_row - 1)
	{
		col = -1;
		while (col++ < info->limit_col - 1)
		{
			if (map[row][col].y >= HORIZONTAL)
				return (1);
		}
	}
	return (0);
}
