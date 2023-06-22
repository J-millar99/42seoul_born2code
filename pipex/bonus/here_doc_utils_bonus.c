/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:09:12 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:52:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_hd(t_cmd *info, int ac, char **av, char **envp)
{
	int		lidx;

	if (ac != 6)
		print_error("Form of command line is wrong", 0);
	info->envp = envp;
	info->outfile = av[5];
	info->limiter = av[2];
	lidx = ft_strlen(av[3]) - 1;
	if (*(av[3]) == 32 || (9 <= *(av[3]) && *(av[3]) <= 13))
		print_error("Command is wrong", 0);
	if (av[3][lidx] == 32 || (9 <= av[3][lidx] && av[3][lidx] <= 13))
		print_error("Command is wrong", 0);
	lidx = ft_strlen(av[4]) - 1;
	if (*(av[4]) == 32 || (9 <= *(av[4]) && *(av[4]) <= 13))
		print_error("Command is wrong", 0);
	if (av[4][lidx] == 32 || (9 <= av[4][lidx] && av[4][lidx] <= 13))
		print_error("Command is wrong", 0);
}

void	execute_hd(t_cmd *info)
{
	char		*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(0);
		if (!ft_strncmp(info->limiter, line, ft_strlen(line) - 1))
		{
			free(line);
			exit(0);
		}
		write(info->hd_fd[1], line, ft_strlen(line));
		free(line);
	}
}
