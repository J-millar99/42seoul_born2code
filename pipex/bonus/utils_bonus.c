/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:12:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/10 20:10:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	split_free(char **strarr)
{
	int		idx;

	idx = 0;
	while (strarr[idx])
	{
		free(strarr[idx]);
		++idx;
	}
	free(strarr);
}

void	print_error(char *error_string, t_cmd *info, int code)
{
	write(1, "pipex: ", 8);
	if (code)
	{
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, ": ", 2);
	}
	write(1, error_string, ft_strlen(error_string));
	write(1, "\n", 1);
	malloc_free(info);
	open_close(info);
	exit(EXIT_FAILURE);
}

void	init_file_fd(t_cmd *info)
{
	info->file[0] = 0;
	info->file[1] = 0;
}
