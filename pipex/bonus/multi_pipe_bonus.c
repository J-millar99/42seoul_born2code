/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:45:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/12 15:03:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	multi_pipe(t_cmd *info, int ac, char **av, char **envp)
{
	pid_t	child;

	check_mp(info, ac, av, envp);
	info->file[0] = open(info->infile, O_RDONLY, 0777);
	if (info->file[0] == -1)
		print_error(info->infile, info, 1);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (info->file[1] == -1)
		print_error(info->outfile, info, 1);
}

void	f_process_mp(t_cmd *info, char *av)
{
	pid_t	child;

	if (pipe(info->mp_fd) == -1)
		print_error("pipe", info, 1);
	child = fork();
	if (child == -1)
		print_error("fork", info, 1);
	if (child == 0)
	{
		close(info->mp_fd[0]);
		dup2(info->mp_fd[1], 1);
		execute_cmdline(info, av);
	}
	else
	{
		close(info->mp_fd[1]);
		dup2(info->mp_fd[0], 0);
		wait(NULL);
	}
}
