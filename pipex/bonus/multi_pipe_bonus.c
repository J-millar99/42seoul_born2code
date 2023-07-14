/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:45:42 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:33:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	multi_pipe(t_cmd *info, int ac, char **av, char **envp)
{
	check_mp(info, ac, av, envp);
	info->file[0] = open(info->infile, O_RDONLY, 0777);
	if (info->file[0] == -1)
		print_error(info->infile, info, 1);
	info->file[1] = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (info->file[1] == -1)
		print_error(info->outfile, info, 1);
}

void	f_process_mp(t_cmd *info, char *av)
{
	pid_t	child;

	if (pipe(info->mp_fd) == -1)
		print_error("pipe", info, 1);
	child = fork();
	if (child == -1)
		print_error("fork", info, 1);
	if (child == 0)
	{
		close(info->mp_fd[0]);
		dup2(info->mp_fd[1], 1);
		execute_cmdline(info, av);
	}
	else
	{
		if (wait(NULL) == -1)
			print_error("wait", info, 1);
		close(info->mp_fd[1]);
		dup2(info->mp_fd[0], 0);
	}
}

void	stop_flag(t_cmd *info, int flag)
{
	if (flag == 1)
	{
		open_close(info);
		exit(1);
	}
}

void	check_command(t_cmd *info, char *av[], int idx, int ac)
{
	char	**cmdline;
	char	*cmd;
	int		flag;

	flag = 0;
	while (idx < ac - 1)
	{
		if (!*(av[idx]))
			print_error_nocmd("command is wrong", &flag);
		else
		{
			cmdline = ft_split(av[idx], ' ');
			if (!cmdline)
				print_error("cmdline", info, 1);
			cmd = check_path(info, cmdline[0]);
			if (!cmd)
				print_error_cmd(cmdline[0], &flag);
			split_free(cmdline);
			free(cmd);
		}
		idx++;
	}
	stop_flag(info, flag);
}
