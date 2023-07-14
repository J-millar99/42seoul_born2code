/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:12:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:33:26 by jaehyji          ###   ########.fr       */
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

void	init_file_fd(t_cmd *info)
{
	info->file[0] = 0;
	info->file[1] = 0;
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
