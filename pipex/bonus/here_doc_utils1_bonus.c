/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:47:47 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 14:49:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_hd(t_hd *info, int ac, char **av, char **envp)
{
	if (ac != 6)
		print_error_hd("Form of command line is wrong", NULL, 0);
	check_space_command_hd(av);
	parsing_cmdline_hd(info, av, envp);
}

void	check_space_command_hd(char **av)
{
	int		lidx;

	lidx = ft_strlen(av[3]) - 1;
	if (*(av[3]) == 32 || (9 <= *(av[3]) && *(av[3]) <= 13))
		print_error_hd("Command is wrong", NULL, 0);
	if (av[3][lidx] == 32 || (9 <= av[3][lidx] && av[3][lidx] <= 13))
		print_error_hd("Command is wrong", NULL, 0);
	lidx = ft_strlen(av[4]) - 1;
	if (*(av[4]) == 32 || (9 <= *(av[4]) && *(av[4]) <= 13))
		print_error_hd("Command is wrong", NULL, 0);
	if (av[4][lidx] == 32 || (9 <= av[4][lidx] && av[4][lidx] <= 13))
		print_error_hd("Command is wrong", NULL, 0);
}

void	parsing_cmdline_hd(t_hd *info, char **av, char **envp)
{
	info->envp = envp;
	info->cmd1 = ft_split(av[3], ' ');
	info->cmd2 = ft_split(av[4], ' ');
	info->outfile = ft_strdup(av[5]);
	info->limiter = av[2];
	if (!(info->cmd1) || !(info->cmd2) || !(info->outfile))
		print_error_hd("Malloc Function Error", info, 1);
	check_file_hd(info);
	check_command_hd(info);
}

void	malloc_free_hd(t_hd *info)
{
	if (!info)
		return ;
	if (info->cmd1)
		split_free(info->cmd1);
	if (info->cmd2)
		split_free(info->cmd2);
	if (info->outfile)
		free(info->outfile);
}

void	print_error_hd(char *error_string, t_hd *info, int code)
{
	if (code)
		perror(error_string);
	else
		write(1, error_string, ft_strlen(error_string));
	malloc_free_hd(info);
	exit(EXIT_FAILURE);
}
