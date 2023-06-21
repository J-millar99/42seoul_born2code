/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 12:01:44 by jaehyji          ###   ########.fr       */
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

void	check_av(t_cmdline *info, int ac, char **av)
{
	int		lidx;

	lidx = ft_strlen(av[2]) - 1;
	init_cmdinfo(info);
	if (*(av[2]) == 32 || (9 <= *(av[2]) && *(av[2]) <= 13))
		print_error("Command is wrong", info);
	if (av[2][lidx] == 32 || (9 <= av[2][lidx] && av[2][lidx] <= 13))
		print_error("Command is wrong", info);
	lidx = ft_strlen(av[3]) - 1;
	if (*(av[3]) == 32 || (9 <= *(av[3]) && *(av[3]) <= 13))
		print_error("Command is wrong", info);
	if (av[3][lidx] == 32 || (9 <= av[3][lidx] && av[3][lidx] <= 13))
		print_error("Command is wrong", info);
}
