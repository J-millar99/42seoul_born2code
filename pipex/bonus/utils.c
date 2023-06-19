/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:51:24 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/19 16:00:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	malloc_free(t_cmdline *info)
{
	if (info->infile)
		free(info->infile);
	if (info->outfile)
		free(info->outfile);
}

void	print_error(char *error_strting, t_cmdline *info)
{
	perror(error_strting);
	malloc_free(info);
	exit(EXIT_FAILURE);
}

void	init_cmdinfo(t_cmdline *info)
{
	info->envp = 0;
	info->infile = 0;
	info->outfile = 0;
}

void	check_av(t_cmdline *info, int ac, char **av, int *file)
{
	int		i;

	init_cmdinfo(info);
	if (ac == 1)
		print_error("Form of command line is wrong", info);
	i = 1;
	while (i < ac)
	{
		while ((*(av[i]) == 32 || (9 <= *(av[i]) && *(av[i]) <= 13)))
			av[i]++;
		if (!*av[i])
			print_error("Form of command line is wrong", info);
		i++;
	}
	return (setting_file(info, ac, av, file));
}

void	setting_file(t_cmdline *info, int ac, char **av, int *file)
{
	if (access(av[1], F_OK) == -1)
		print_error("Infile does not exist", info);
	file[0] = open(av[1], O_RDONLY, 0777);
	if (file[0] == -1)
		print_error("Open Function Error to infile", info);
	file[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file[1] == -1)
	{
		close(file[0]);
		print_error("Open Function Error to outfile", info);
	}
}
