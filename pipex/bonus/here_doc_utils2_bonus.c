/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:09:12 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 14:48:55 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_file_hd(t_hd *info)
{
	int		fd;

	fd = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		print_error_hd("Open Function Error to outfile", info, 1);
	close(fd);
}

void	check_command_hd(t_hd *info)
{
	char	*command1;
	char	*command2;

	command1 = check_path_hd(info, info->cmd1[0]);
	if (!command1)
		print_error_hd("Command is wrong", info, 1);
	command2 = check_path_hd(info, info->cmd2[0]);
	if (!command2)
	{
		free(command1);
		print_error_hd("Command is wrong", info, 1);
	}
	free(command1);
	free(command2);
}

char	*check_path_hd(t_hd *info, char *cmd)
{
	char	**paths;
	char	*path;
	int		idx;
	char	*cmd_file;

	idx = -1;
	paths = make_paths_hd(info);
	while (paths[++idx])
	{
		path = ft_strjoin(paths[idx], "/");
		cmd_file = ft_strjoin(path, cmd);
		check_some_hd(paths, &path, &cmd_file, info);
		free(path);
		if (access(cmd_file, F_OK) == 0)
		{
			split_free(paths);
			return (cmd_file);
		}
		free(cmd_file);
	}
	split_free(paths);
	return (NULL);
}

char	**make_paths_hd(t_hd *info)
{
	int		idx;
	char	**paths;

	idx = 0;
	while (!ft_strnstr(info->envp[idx], "PATH", 4))
		++idx;
	paths = ft_split(info->envp[idx] + 5, ':');
	if (!paths)
		print_error_hd("Malloc Function Error", info, 1);
	return (paths);
}

void	check_some_hd(char **paths, char **path, char **cmd_file, t_hd *info)
{
	if (!(*path))
	{
		split_free(paths);
		print_error_hd("Malloc Function Error", info, 1);
	}
	if (!(*cmd_file))
	{
		split_free(paths);
		free(*path);
		print_error_hd("Malloc Function Error", info, 1);
	}
}
