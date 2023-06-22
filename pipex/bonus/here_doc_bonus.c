/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:29:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_cmd *info, int ac, char **av, char **envp)
{
	pid_t	child;

	check_hd(info, ac, av, envp);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (info->file[1] == -1)
		print_error("Open Function Error", 1);
	if (pipe(info->hd_fd) == -1)
		print_error("Pipe Function Error", 1);
	child = fork();
	if (child == -1)
		print_error("Fork Function Error", 1);
	f_process_hd(child, info);
}

void	f_process_hd(pid_t child, t_cmd *info)
{
	if (child == 0)
		c_process_hd(info, info->hd_fd);
	else
		p_process_hd(info, info->hd_fd);
}

void	c_process_hd(t_cmd *info, int *hd_fd)
{
	close(hd_fd[0]);
	execute_hd(info);
}

void	p_process_hd(t_cmd *info, int *hd_fd)
{
	close(hd_fd[1]);
	dup2(hd_fd[0], STDIN_FILENO);
	wait(NULL);
}
