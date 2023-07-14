/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:24:26 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_cmd(char *cmd, int *flag)
{
	write(1, "pipex: ", 8);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, ": ", 2);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	*flag = 1;
}

void	print_error_nocmd(char *cmd, int *flag)
{
	write(1, "pipex: ", 8);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	*flag = 1;
}

void	check_command(t_cmd *info)
{
	char	*cmd;
	int		flag;

	flag = 0;
	if (!*(info->cmd1))
		print_error_nocmd("command is wrong", &flag);
	if (!*(info->cmd2))
		print_error_nocmd("command is wrong", &flag);
	if (*(info->cmd1))
	{
		cmd = check_path(info, info->cmd1[0]);
		if (!cmd)
			print_error_cmd(info->cmd1[0], &flag);
	}
	if (*(info->cmd2))
	{
		cmd = check_path(info, info->cmd2[0]);
		if (!cmd)
			print_error_cmd(info->cmd2[0], &flag);
	}
	stop_flag(info, flag);
	free(cmd);
}

void	stop_flag(t_cmd *info, int flag)
{
	if (flag == 1)
	{
		open_close(info);
		exit(1);
	}
}
