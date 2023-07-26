/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:21:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/26 15:07:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *filename, t_info *info)
{
	if (access(filename, F_OK) == -1)
		print_error(filename, 1, info);
	info->fd = open(filename, O_RDONLY, 0644);
	if (info->fd == -1)
		print_error(filename, 1, info);
}

void	check_no_data(char *line, t_info *info)
{
	if (!line || !*line)
		print_error("No data found.", 0, info);
	if (*line)
		while (*line == 32 || (9 <= *line && *line <= 13))
			line++;
	if (!*line)
		print_error("No data found.", 0, info);
}

void	check_map(char *av, t_info *info)
{
	char	*line;

	check_file(av, info);
	line = get_next_line(info->fd);
	check_no_data(line, info);
	check_possible_map(line, info);
	close(info->fd);
	info->fd = 0;
}

int	check_num(char **arr)
{
	int		cnt;

	cnt = 0;
	if (!arr || !*arr)
		return (0);
	while (*arr)
	{
		cnt++;
		arr++;
	}
	return (cnt);
}

void	check_possible_map(char *line, t_info *info)
{
	char	**arr;
	int		stdnum;
	int		arrnum;

	arr = ft_split(line, ' ');
	stdnum = check_num(arr);
	free_arr(arr, info);
	while (line && *line)
	{
		free(line);
		line = get_next_line(info->fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		arrnum = check_num(arr);
		free_arr(arr, info);
		if (arrnum < stdnum)
			print_error("Found wrong line length. Exiting.", 0, info);
	}
}
