/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:43:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 20:24:41 by jaehyji          ###   ########.fr       */
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
