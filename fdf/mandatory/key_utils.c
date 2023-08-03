/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 22:46:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_key(t_mlx *mlx)
{
	mlx_key_hook(mlx->wptr, &on_key_press, mlx);
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mptr, mlx->wptr);
		exit(0);
	}
	return (0);
}
