/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:51:24 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 13:14:30 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_av(t_cmdline *info, int ac, char **av, int *file)
{
	int		idx;
	int		lidx;

	init_cmdinfo(info);
	idx = 2;
	while (idx < ac -1)
	{
		lidx = ft_strlen(av[idx] - 1);
		if (*(av[idx]) == 32 || (9 <= *(av[idx]) && *(av[idx]) <= 13))
			print_error("Command is wrong", info, 0);
		if (av[idx][lidx] == 32 || (9 <= av[idx][lidx] && av[idx][lidx] <= 13))
			print_error("Command is wrong", info, 0);
		idx++;
	}
	return (setting_file(info, ac, av, file));
}

void	setting_file(t_cmdline *info, int ac, char **av, int *file)
{
	if (access(av[1], F_OK) == -1)
		print_error("Infile does not exist", info, 1);
	file[0] = open(av[1], O_RDONLY, 0777);
	if (file[0] == -1)
		print_error("Open Function Error to infile", info, 1);
	file[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file[1] == -1)
	{
		close(file[0]);
		print_error("Open Function Error to outfile", info, 1);
	}
}
