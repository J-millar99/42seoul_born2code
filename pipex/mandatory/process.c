/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 17:15:22 by jaehyji          ###   ########.fr       */
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

void	c_process(t_cmdline *info, int *fd, int infile)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmdline(info, info->cmd1);
}

void	p_process(t_cmdline *info, int *fd, int outfile)
{
	close(fd[1]);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	execute_cmdline(info, info->cmd2);
}

void	f_process(pid_t child, t_cmdline *info, int *fd, int *file)
{
	if (child == 0)
		c_process(info, fd, file[0]);
	else
	{
		waitpid(child, NULL, 0);
		p_process(info, fd, file[1]);
	}
}
