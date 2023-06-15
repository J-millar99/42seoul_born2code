/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/15 14:21:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command(t_cmdline *info)
{
	char	*command1;
	char	*command2;

	command1 = check_path(info, info->cmd1[0]);
	if (!command1)
		print_error("Command is wrong", info);
	command2 = check_path(info, info->cmd2[0]);
	if (!command2)
	{
		free(command1);
		print_error("Command is wrong", info);
	}
	free(command1);
	free(command2);
}

char	*check_path(t_cmdline *info, char *cmd)
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
		check_some(paths, path, cmd_file, info);
		cmd_file = ft_strjoin(path, cmd);
		free(path);
		check_some(paths, path, cmd_file, info);
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

void	check_some(char **paths, char **path, char **cmd_file, t_cmdline *info)
{
	if (!path)
	{
		split_free(paths);
		print_error("Malloc Function Error", info);
	}
	if (!cmd_file)
	{
		split_free(paths);
		print_error("Malloc Function Error", info);
	}
}

char	**make_paths(t_cmdline *info)
{
	int		idx;
	char	**paths;

	idx = 0;
	while (!ft_strnstr(info->envp[idx], "PATH", 4))
		++idx;
	paths = ft_split(info->envp[idx] + 5, ':');
	if (!paths)
		print_error("Malloc Function Error", info);
	return (paths);
}
