/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/18 15:48:02 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command(t_cmd *info, char *av)
{
	char	**cmdline;
	char	*cmd;

	if (!(*av))
		print_error_cmd1("permission denied:");
	else
	{
		cmdline = ft_split(av, ' ');
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
}

void	check_commandline(t_cmd *info, char *av[])
{
	int		idx;

	idx = 2;
	while (idx < 4)
		check_command(info, av[idx++]);
}
