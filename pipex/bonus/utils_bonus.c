/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:12:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 17:13:49 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	init_info(t_cmd *info)
{
	info->file[0] = 0;
	info->file[1] = 0;
	info->hd_fd[0] = 0;
	info->hd_fd[1] = 0;
	info->mp_fd[0] = 0;
	info->mp_fd[1] = 0;
	info->infile = 0;
	info->outfile = 0;
	info->envp = 0;
	info->limiter = 0;
}

void	open_close(t_cmd *info)
{
	if (!info)
		return ;
	if (info->file[0])
		close(info->file[0]);
	if (info->file[1])
		close(info->file[1]);
}

void	check_command(t_cmd *info, char *av[], int idx, int ac)
{
	char	**cmdline;
	char	*cmd;

	while (idx < ac - 1)
	{
		if (!*(av[idx]))
			print_error_cmd1("permission denied:");
		else
		{
			cmdline = ft_split(av[idx], ' ');
			if (!cmdline)
				print_error("cmdline", info, 1);
			cmd = check_path(info, cmdline[0]);
			if (!cmd)
				print_error("cmd", info, 1);
			if (access(cmd, F_OK) != 0)
				print_error_cmd2("command not found: ", cmd);
			split_free(cmdline);
			free(cmd);
		}
		idx++;
	}
}
