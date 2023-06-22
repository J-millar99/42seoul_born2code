/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:45:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:18:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	multi_pipe(t_cmd *info, int ac, char **av, char **envp)
{
	t_cmd	info;
	pid_t	child;

	check_mp(info, ac, av, envp);
	info->file[0] = open(info->infile, O_RDONLY, 0777);
	if (info->file[0] == -1)
		print_error("Open Function Error", 1);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (info->file[1] == -1)
		print_error("Open Function Error", 1);
	if (pipe(info->mp_fd) == -1)
		print_error("Pipe Function Error", 1);
	child = fork();
	if (child == -1)
		print_error("Fork Function Error", 1);
}

void	f_process_mp(t_cmd *info, char *av)
{
	pid_t	child;

	if (pipe(info->mp_fd) == -1)
		error();
	child = fork();
	if (child == -1)
		error();
	if (child == 0)
	{
		close(info->mp_fd[0]);
		dup2(info->mp_fd[1], STDOUT_FILENO);
		execute_cmdline(info, av);
	}
	else
	{
		close(info->mp_fd[1]);
		dup2(info->mp_fd[0], STDIN_FILENO);
		waitpid(child, NULL, 0);
	}
}
