/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/09/21 20:54:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(t_cmd *info)
{
	if (access(info->infile, F_OK) == -1)
		print_error(info->infile, info, 1);
	info->file[0] = open(info->infile, O_RDONLY, 0777);
	if (info->file[0] == -1)
		print_error(info->infile, info, 1);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (info->file[1] == -1)
		print_error(info->outfile, info, 1);
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
	return (ft_strdup(cmd));
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
		print_error("paths", info, 1);
	}
	if (!(*cmd_file))
	{
		split_free(paths);
		free(*path);
		print_error("cmd_file", info, 1);
	}
}
