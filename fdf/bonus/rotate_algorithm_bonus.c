/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algorithm_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:15:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 16:37:46 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_std_x(t_map *map, double theta)
{
	double	std_x;
	double	std_y;
	double	std_z;

	std_x = map->x;
	std_y = map->y;
	std_z = map->z;
	map->x = std_x;
	map->y = std_y * cos(theta) + (std_z * sin(theta) * -1);
	map->z = std_y * sin(theta) + std_z * cos(theta);
}

void	rotate_std_y(t_map *map, double theta)
{
	double	std_x;
	double	std_y;
	double	std_z;

	std_x = map->x;
	std_y = map->y;
	std_z = map->z;
	map->x = std_x * cos(theta) + (std_z * sin(theta) * -1);
	map->y = std_y;
	map->z = std_x * sin(theta) + std_z * cos(theta);
}

void	rotate_std_z(t_map *map, double theta)
{
	double	std_x;
	double	std_y;
	double	std_z;

	std_x = map->x;
	std_y = map->y;
	std_z = map->z;
	map->x = std_x * cos(theta) + (std_y * sin(theta) * -1);
	map->y = std_x * sin(theta) + std_y * cos(theta);
	map->z = std_z;
}
