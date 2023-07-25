/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:21:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 20:09:10 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *filename, int *fd)
{
	if (access(filename, F_OK) == -1)
		print_error(filename, 1, fd);
	*fd = open(filename, O_RDONLY, 0644);
	if (*fd == -1)
		print_error(filename, 1, fd);
}

void	check_no_data(char *line, int *fd)
{
	if (!line || !*line)
		print_error("No data found.", 0, fd);
	if (*line)
		while (*line == 32 || (9 <= *line && *line <= 13))
			line++;
	if (!*line)
		print_error("No data found.", 0, fd);
}

void	check_map(char *av, int *fd)
{
	char	*line;

	check_file(av, fd);
	line = get_next_line(*fd);
	check_no_data(line, fd);
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

void	check_possible_map(int *fd, char *line)
{
	char	**arr;
	int		stdnum;
	int		arrnum;

	arr = ft_split(line, ' ');
	stdnum = check_num(arr);
	free_arr(arr, fd);
	while (line && *line)
	{
		free(line);
		line = get_next_line(*fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		arrnum = check_num(arr);
		free_arr(arr, fd);
		if (arrnum < stdnum)
			print_error("Found wrong line length. Exiting.", 0, fd);
	}
}
