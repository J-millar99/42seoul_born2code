/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:02 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 14:49:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmdinfo(t_cmdline *info)
{
	info->envp = 0;
	info->infile = 0;
	info->cmd1 = 0;
	info->cmd2 = 0;
	info->outfile = 0;
}

void	parsing_cmdline(t_cmdline *info, char **av, char **envp)
{
	info->envp = envp;
	info->infile = ft_strdup(av[1]);
	info->cmd1 = ft_split(av[2], ' ');
	info->cmd2 = ft_split(av[3], ' ');
	info->outfile = ft_strdup(av[4]);
	if (!(info->infile) || !(info->cmd1) || !(info->cmd2) || !(info->outfile))
		print_error("Malloc Function Error", info);
	check_command(info);
}

void	malloc_free(t_cmdline *info)
{
	if (info->infile)
		free(info->infile);
	if (info->cmd1)
		split_free(info->cmd1);
	if (info->cmd2)
		split_free(info->cmd2);
	if (info->outfile)
		free(info->outfile);
}

void	split_free(char **strarr)
{
	int		idx;

	idx = 0;
	while (strarr[idx])
	{
		free(strarr[idx]);
		++idx;
	}
	free(strarr);
}

void	execute_cmdline(t_cmdline *info, char **cmd)
{
	char	*exe;

	exe = check_path(info, cmd[0]);
	if (!exe)
		print_error("Malloc Function Error", info);
	if (execve(exe, cmd, info->envp) == -1)
		print_error("Execve Function Error", info);
	free(exe);
}
