/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/01 15:29:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*
	증감제한구간 설정.
	회전.
	다른 투영.
	makefile 현재 수정됨.
*/

void	input_key(t_mlx *mlx)
{
	mlx_key_hook(mlx->wptr, &on_key_press, mlx);
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == PLUS || keycode == MINUS)
		key_size(mlx, keycode);
	else if (keycode == X || keycode == Y || keycode == Z)
	{
		mlx_clear_window(mlx->mptr, mlx->wptr);
		key_rotate(mlx, keycode);
	}
	return (0);
}
