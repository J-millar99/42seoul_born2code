/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:21:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 19:01:30 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *filename)
{
	int		fd;

	if (access(filename, F_OK) == -1)
		print_error(filename, 1);
	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
		print_error(filename, 1);
	return (fd);
}

void	check_no_data(char *line)
{
	if (!line || !*line)
		print_error("No data found.", 0);
	if (*line)
		while (*line == 32 || (9 <= *line && *line <= 13))
			line++;
	if (!*line)
		print_error("No data found.", 0);
}

void	check_map(char *av)
{
	int		fd;
	char	*line;

	fd = check_file(av);
	line = get_next_line(fd);
	check_no_data(line);
	check_possible_map(fd, line);
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

void	check_possible_map(int fd, char *line)
{
	char	**arr;
	int		stdnum;
	int		arrnum;

	arr = ft_split(line, ' ');
	stdnum = check_num(arr);
	free_arr(arr);
	while (line && *line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		arrnum = check_num(arr);
		free_arr(arr);
		if (arrnum < stdnum)
			print_error("Found wrong line length. Exiting.", 0);
	}
}
