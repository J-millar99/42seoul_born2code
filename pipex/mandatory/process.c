/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 15:30:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	infile: (3)
	outfile: (4)
	fd[0]: read pipe fd (5)
	fd[1]: write pipe fd (6)
	
	// 0 -> 3 (infile fd)
	// 1 -> 6 (write pipe fd)
	// now, stdin fd(0) is infile fd(3), stdout fd(1) is write pipe fd (6)

	// 1 -> 4(outfile fd)
	// 0 -> 5(read pipe fd)
	// now, stdin fd(0) is read pipe fd(5), stdout fd(1) is outfile fd (4)
*/

void	f_process(pid_t child, t_cmd *info)
{
	if (child == 0)
		c_process(info);
	else
	{
		waitpid(child, NULL, 0);
		p_process(info);
	}
}

void	c_process(t_cmd *info)
{
	close(info->fd[0]);
	dup2(info->file[0], STDIN_FILENO);
	dup2(info->fd[1], STDOUT_FILENO);
	execute_cmdline(info, info->cmd1);
}

void	p_process(t_cmd *info)
{
	close(info->fd[1]);
	dup2(info->file[1], STDOUT_FILENO);
	dup2(info->fd[0], STDIN_FILENO);
	execute_cmdline(info, info->cmd2);
}
