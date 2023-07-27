/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:02:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/27 00:30:56 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_key(void *win_ptr)
{
	mlx_key_hook(win_ptr, &on_key_press, NULL);
}

int	on_key_press(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}
