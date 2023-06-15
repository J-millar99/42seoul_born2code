/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/15 12:16:31 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_process(t_cmdline *info, int *fd)
{
	int		infile_fd;

	infile_fd = open(info->infile, O_RDONLY, 0777);
	if (infile_fd == -1)
		print_error("Open Function Error at infile", info);
	close(fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmdline(info, info->cmd1);
}

void	p_process(t_cmdline *info, int *fd)
{
	int		outfile_fd;

	outfile_fd = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		print_error("Open Function Error at outfile", info);
	close(fd[1]);
	dup2(outfile_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	execute_cmdline(info, info->cmd2);
}
