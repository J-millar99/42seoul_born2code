/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:36:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 14:37:49 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initializing_fileinfo(t_file *info, char *filename)
{
	info->limit_row = 0;
	info->limit_col = 0;
	info->width = 0;
	info->height = 0;
	info->mtp_x = 2;
	info->mtp_y = 2;
	info->fd = 0;
	info->filename = filename;
}

void	initializing_coordinates_data(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->color = 0;
}
