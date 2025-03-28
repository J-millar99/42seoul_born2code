/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:21:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 11:30:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checking_map_data(t_file *info)
{
	char	*line;

	checking_file(info);
	line = get_next_line(info->fd);
	checking_no_data(line, info);
	info->limit_row++;
	checking_possible_map(line, info);
	close(info->fd);
	info->fd = 0;
	if (info->limit_row > VERTICAL || info->limit_col > HORIZONTAL)
		print_error("Too many coordinates", 0, info);
}

void	checking_file(t_file *info)
{
	char	*tmp;

	tmp = &(info->filename)[ft_strlen(info->filename) - 4];
	if (ft_strncmp(tmp, ".fdf", 4))
		print_error("The file does not have the extension \".fdf\".", 0, info);
	info->fd = open(info->filename, O_RDONLY, 0644);
	if (info->fd == -1)
		print_error(info->filename, 1, info);
}

void	checking_no_data(char *line, t_file *info)
{
	if (!line || !*line)
		print_error("No data found.", 0, info);
	if (*line)
		while (*line == 32 || (9 <= *line && *line <= 13))
			line++;
	if (!*line)
		print_error("No data found.", 0, info);
}

void	checking_possible_map(char *line, t_file *info)
{
	int		comp;

	info->limit_col = word_count(line, ' ');
	while (line && *line)
	{
		free(line);
		line = get_next_line(info->fd);
		if (!line)
			break ;
		info->limit_row++;
		comp = word_count(line, ' ');
		if (comp < info->limit_col)
			print_error("Found wrong line length. Exiting.", 0, info);
	}
}
