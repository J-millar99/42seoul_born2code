/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 14:22:55 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_key(void *mlx_ptr, void *win_ptr)
{
	mlx_key_hook(win_ptr, &on_key_press, NULL);
}

int	on_key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return (0);
}
