/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:08 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/10 19:29:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	malloc_free(t_cmd *info)
{
	if (!info)
		return ;
	if (info->cmd1)
		split_free(info->cmd1);
	if (info->cmd2)
		split_free(info->cmd2);
}

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

void	open_close(t_cmd *info)
{
	if (!info)
		return ;
	if (info->file[0])
		close(info->file[0]);
	if (info->file[1])
		close(info->file[1]);
}
