/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:43:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 14:37:09 by jaehyji          ###   ########.fr       */
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
