/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:02:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/27 09:47:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_fdf(char **str)
{
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while ('0' <= **str && **str <= '9')
	{
		value = (value * 10) + (**str - '0');
		(*str)++;
	}
	value *= sign;
	return (value);
}

void	ft_atoi_z(t_map *map, char *str)
{
	map->z = ft_atoi_fdf(&str);
	map->color = 0xffffff;
	if (*str == ',')
	{
		str++;
		ft_atoi_color(map, &str);
	}
}

void	ft_atoi_color(t_map *map, char **str)
{
	if (!ft_strncmp(*str, "0x", 2) || !ft_strncmp(*str, "0X", 2))
	{
		(*str)++;
		(*str)++;
		map->color = ft_atoi_hex(*str);
	}
	else
		map->color = ft_atoi_fdf(str);
}

int	ft_atoi_hex(char *str)
{
	int		value;

	value = 0;
	while (('0' <= *str && *str <= '9') || \
			('a' <= *str && *str <= 'f') || \
			('A' <= *str && *str <= 'F'))
	{
		if ('0' <= *str && *str <= '9')
			value = (value * 16) + (*str - '0');
		else if ('a' <= *str && *str <= 'f')
			value = (value * 16) + 10 + (*str - 'a');
		else
			value = (value * 16) + 10 + (*str - 'A');
		str++;
	}
	return (value);
}
