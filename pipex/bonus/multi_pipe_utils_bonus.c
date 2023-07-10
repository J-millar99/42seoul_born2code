/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:28:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/10 20:25:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_mp(t_cmd *info, int ac, char **av, char **envp)
{
	int		lidx;

	info->envp = envp;
	info->outfile = av[5];
	info->limiter = av[2];
	lidx = ft_strlen(av[3]) - 1;
	if (*(av[3]) == 32 || (9 <= *(av[3]) && *(av[3]) <= 13))
		print_error("Command is wrong", 0);
	if (av[3][lidx] == 32 || (9 <= av[3][lidx] && av[3][lidx] <= 13))
		print_error("Command is wrong", 0);
	lidx = ft_strlen(av[4]) - 1;
	if (*(av[4]) == 32 || (9 <= *(av[4]) && *(av[4]) <= 13))
		print_error("Command is wrong", 0);
	if (av[4][lidx] == 32 || (9 <= av[4][lidx] && av[4][lidx] <= 13))
		print_error("Command is wrong", 0);
}

void	execute_cmdline(t_cmd *info, char *cmdline)
{
	char	*exe;
	char	**cmd;

	cmd = ft_split(cmdline, ' ');
	if (!cmd)
		print_error("Malloc Function Error", 1);
	exe = check_path(info, cmd[0]);
	if (!exe)
		print_error("Malloc Function Error", 1);
	if (execve(exe, cmd, info->envp) == -1)
		print_error("Execve Function Error", 1);
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
		print_error("Malloc Function Error", 1);
	return (paths);
}

void	check_some(char **paths, char **path, char **cmd_file, t_cmd *info)
{
	if (!(*path))
	{
		split_free(paths);
		print_error("Malloc Function Error", 1);
	}
	if (!(*cmd_file))
	{
		split_free(paths);
		free(*path);
		print_error("Malloc Function Error", 1);
	}
}
