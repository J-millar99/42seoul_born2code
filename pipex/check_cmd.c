/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 13:22:44 by jaehyji          ###   ########.fr       */
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
	int		i;

	init_cmdinfo(info);
	i = 1;
	while (i < ac)
	{
		while ((*(av[i]) == 32 || (9 <= *(av[i]) && *(av[i]) <= 13)))
			av[i]++;
		if (!*av[i])
			print_error("Form of command line is wrong", info);
		i++;
	}
}
