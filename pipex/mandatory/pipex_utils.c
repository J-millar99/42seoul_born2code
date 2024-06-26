/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:02 by jaehyji           #+#    #+#             */
/*   Updated: 2023/09/21 20:39:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmdinfo(t_cmd *info)
{
	info->child[0] = 0;
	info->child[0] = 0;
	info->file[0] = 0;
	info->file[1] = 0;
	info->envp = 0;
	info->infile = 0;
	info->outfile = 0;
}

void	setting_cmdinfo(t_cmd *info, char **av, char **envp)
{
	init_cmdinfo(info);
	info->envp = envp;
	info->infile = av[1];
	info->outfile = av[4];
}

void	execute_cmdline(t_cmd *info, char *av)
{
	char	*exe;
	char	**cmdline;

	cmdline = ft_split(av, ' ');
	if (!cmdline)
		print_error("cmdline", info, 1);
	exe = check_path(info, cmdline[0]);
	if (!exe)
		print_error("exe", info, 1);
	if (execve(exe, cmdline, info->envp) == -1)
	{
		close(1);
		print_error("execve", info, 1);
	}
}
