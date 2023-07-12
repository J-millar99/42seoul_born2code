/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:28:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/12 14:20:11 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_mp(t_cmd *info, int ac, char **av, char **envp)
{
	int		lidx;

	info->envp = envp;
	info->infile = av[1];
	info->outfile = av[ac - 1];
}

void	execute_cmdline(t_cmd *info, char *cmdline)
{
	char	*exe;
	char	**cmd;

	cmd = ft_split(cmdline, ' ');
	if (!cmd)
		print_error("cmd", info, 1);
	exe = check_path(info, cmd[0]);
	if (!exe)
		print_error("exe", info, 1);
	if (execve(exe, cmd, info->envp) == -1)
		print_error("execve", info, 1);
}

char	*check_path(t_cmd *info, char *cmd)
{
	char	**paths;
	char	*path;
	int		idx;
	char	*cmd_file;

	idx = -1;
	paths = make_paths(info);
	while (paths[++idx])
	{
		path = ft_strjoin(paths[idx], "/");
		cmd_file = ft_strjoin(path, cmd);
		check_some(paths, &path, &cmd_file, info);
		free(path);
		if (access(cmd_file, F_OK) == 0)
		{
			split_free(paths);
			return (cmd_file);
		}
		free(cmd_file);
	}
	split_free(paths);
	return (0);
}

char	**make_paths(t_cmd *info)
{
	int		idx;
	char	**paths;

	idx = 0;
	while (!ft_strnstr(info->envp[idx], "PATH", 4))
		++idx;
	paths = ft_split(info->envp[idx] + 5, ':');
	if (!paths)
		print_error("paths", info, 1);
	return (paths);
}

void	check_some(char **paths, char **path, char **cmd_file, t_cmd *info)
{
	if (!(*path))
	{
		split_free(paths);
		print_error("path", info, 1);
	}
	if (!(*cmd_file))
	{
		split_free(paths);
		free(*path);
		print_error("cmd_file", info, 1);
	}
}
