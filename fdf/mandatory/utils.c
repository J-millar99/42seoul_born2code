/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:43:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 22:48:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	word_count(const char *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (is_sep(*s, c) && *s != '\0')
			s++;
		if (!is_sep(*s, c) && *s != '\0' && *s != '\n')
			cnt++;
		while (!is_sep(*s, c) && *s != '\0')
			s++;
	}
	return (cnt);
}

void	free_split(char **array)
{
	int		idx;

	if (!array || !*array)
		return ;
	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		++idx;
	}
	free(array);
}

void	free_map(t_map **map, t_file *info)
{
	int		x;

	x = 0;
	while (x < info->limit_row)
	{
		free(map[x]);
		x++;
	}
	free(map);
}

void	get_height(t_map **map, t_file *info)
{
	int		row;
	int		col;

	row = 0;
	while (row < info->limit_row)
	{
		col = 0;
		while (col < info->limit_col)
		{
			if (info->max_height <= map[row][col].x)
				info->max_height = map[row][col].x;
			if (info->min_height > map[row][col].x)
				info->min_height = map[row][col].x;
			++col;
		}
		++row;
	}
}
