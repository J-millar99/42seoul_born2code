/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:38:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 18:24:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	f_process_fd(pid_t child, t_cmd *info)
{
	if (child == 0)
		c_process_hd(info, info->fd);
	else
		p_process_hd(info, info->fd);
}

void	c_process_hd(t_cmd *info, int *fd)
{
	close(fd[0]);
	execute_hd(info);
}

void	p_process_hd(t_cmd *info, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
}
