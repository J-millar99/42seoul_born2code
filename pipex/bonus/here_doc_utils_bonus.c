/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:09:12 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/12 15:28:50 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_hd(t_cmd *info, int ac, char **av, char **envp)
{
	if (ac != 6)
		print_error("Form of command line is wrong", info, 0);
	info->envp = envp;
	info->outfile = av[5];
	info->limiter = av[2];
}

void	execute_hd(t_cmd *info)
{
	char		*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(0);
		if (!ft_strncmp(info->limiter, line, ft_strlen(line) + 1))
		{
			free(line);
			exit(0);
		}
		write(info->hd_fd[1], line, ft_strlen(line));
		write(info->hd_fd[1], "\n", 1);
		free(line);
	}
}
