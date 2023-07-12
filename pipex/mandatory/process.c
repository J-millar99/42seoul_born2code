/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/12 13:45:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_process(pid_t child, t_cmd *info)
{
	if (child == 0)
		c_process(info);
	else
	{
		if (wait(NULL) == -1)
			print_error("wait", info, 1);
		p_process(info);
	}
}

void	c_process(t_cmd *info)
{
	close(info->fd[0]);
	dup2(info->file[0], 0);
	dup2(info->fd[1], 1);
	execute_cmdline(info, info->cmd1);
}

void	p_process(t_cmd *info)
{
	close(info->fd[1]);
	dup2(info->file[1], 1);
	dup2(info->fd[0], 0);
	execute_cmdline(info, info->cmd2);
}
