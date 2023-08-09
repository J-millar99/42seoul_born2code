/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 17:10:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_cmd *info, int ac, char **av, char **envp)
{
	pid_t	child;

	init_info(info);
	check_hd(info, ac, av, envp);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (info->file[1] == -1)
		print_error(info->outfile, info, 1);
	if (pipe(info->hd_fd) == -1)
		print_error("pipe", info, 1);
	child = fork();
	if (child == -1)
		print_error("fork", info, 1);
	if (child == 0)
		c_process_hd(info);
	else
	{
		if (wait(NULL) == -1)
			print_error("wait", info, 1);
		p_process_hd(info);
	}
}

void	c_process_hd(t_cmd *info)
{
	close(info->hd_fd[0]);
	execute_hd(info);
}

void	p_process_hd(t_cmd *info)
{
	close(info->hd_fd[1]);
	dup2(info->hd_fd[0], 0);
	close(info->hd_fd[0]);
}
