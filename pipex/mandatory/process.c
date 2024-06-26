/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/09/21 20:48:32 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_process1(t_cmd *info, char **av)
{
	int		fd[2];

	if (pipe(fd) == -1)
		print_error("pipe", info, 1);
	info->child[0] = fork();
	if (info->child[0] == -1)
		print_error("fork", info, 1);
	if (info->child[0] == 0)
	{
		close(fd[0]);
		close(info->file[1]);
		dup2(info->file[0], 0);
		dup2(fd[1], 1);
		close(info->file[0]);
		close(fd[1]);
		execute_cmdline(info, av[2]);
	}
	f_process2(info, av, fd);
}

void	f_process2(t_cmd *info, char **av, int *fd)
{
	info->child[1] = fork();
	if (info->child[1] == -1)
		print_error("fork", info, 1);
	if (info->child[1] == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(info->file[1], 1);
		close(fd[0]);
		close(info->file[1]);
		execute_cmdline(info, av[3]);
	}
	f_process3(info, fd);
}

void	f_process3(t_cmd *info, int *fd)
{
	int		status;
	int		i;

	i = 0;
	close(fd[0]);
	close(fd[1]);
	open_close(info);
	while (i < 2)
	{
		if (waitpid(info->child[i], &status, 0) == -1)
			print_error("wait", info, 1);
		i++;
	}
	if (WEXITSTATUS(status))
		exit(1);
	exit(0);
}
