/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:12:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 18:55:21 by jaehyji          ###   ########.fr       */
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

void	print_error(char *error_string, int code)
{
	if (code)
		perror(error_string);
	else
		write(1, error_string, ft_strlen(error_string));
	exit(EXIT_FAILURE);
}

void	init_file_fd(t_cmd *info)
{
	info->file[0] = 0;
	info->file[1] = 0;
}
