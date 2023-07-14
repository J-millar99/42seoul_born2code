/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:02 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 14:58:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmdinfo(t_cmd *info)
{
	info->file[0] = 0;
	info->file[1] = 0;
	info->envp = 0;
	info->infile = 0;
	info->cmd1 = 0;
	info->cmd2 = 0;
	info->outfile = 0;
}

void	parsing_cmdline(t_cmd *info, char **av, char **envp)
{
	info->envp = envp;
	info->infile = av[1];
	info->cmd1 = ft_split(av[2], ' ');
	if (!(info->cmd1))
		print_error("cmd1", info, 1);
	info->cmd2 = ft_split(av[3], ' ');
	if (!(info->cmd2))
		print_error("cmd2", info, 1);
	info->outfile = av[4];
}

void	execute_cmdline(t_cmd *info, char **cmd)
{
	char	*exe;

	exe = check_path(info, cmd[0]);
	if (!exe)
		print_error("exe", info, 1);
	if (execve(exe, cmd, info->envp) == -1)
		print_error("execve", info, 1);
}
