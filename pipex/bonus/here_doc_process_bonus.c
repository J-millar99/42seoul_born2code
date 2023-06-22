/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:38:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 15:05:12 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	f_process_fd(pid_t child, t_hd *info, int *fd)
{
	if (child == 0)
		c_process_hd(info, fd);
	else
	{
		waitpid(child, NULL, 0);
		p_process_hd(info, fd);
	}
}

void	c_process_hd(t_hd *info, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmdline_hd(info, info->cmd1, 'c');
}

void	p_process_hd(t_hd *info, int *fd)
{
	int		outfile;

	outfile = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		print_error_hd("Open Function Error to outfile", info, 1);
	close(fd[1]);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	execute_cmdline_hd(info, info->cmd2, 'p');
}

int	execute_hd(t_hd *info)
{
	char		*line;
	static char	*backup;

	backup = ft_strdup("");
	if (!backup)
		print_error_hd("Malloc Function Error", info, 1);
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(info->limiter, line, ft_strlen(line) - 1))
		{
			free(line);
			write(1, backup, ft_strlen(backup));
			free(backup);
			exit(0);
		}
		backup = ft_strjoin(backup, line);
		free(line);
	}
	return (1);
}

void	execute_cmdline_hd(t_hd *info, char **cmd, char f)
{
	char	*exe;

	exe = check_path_hd(info, cmd[0]);
	if (!exe)
		print_error_hd("Malloc Function Error", info, 1);
	if (f == 'c')
		while (execute_hd(info))
			if (execve(exe, cmd, info->envp) == -1)
				print_error_hd("Execve Function Error", info, 1);
	if (f == 'p')
		if (execve(exe, cmd, info->envp) == -1)
			print_error_hd("Execve Function Error", info, 1);
	free(exe);
}
