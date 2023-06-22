/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:20:22 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **envp)
{
	t_cmd	info;
	int		fd[2];
	int		idx;

	if (ac >= 5)
	{
		init_file_fd(&info);
		if (!ft_strcmp(av[1], "here_doc"))
		{
			idx = 3;
			here_doc(&info, ac, av, envp);
		}
		else
		{
			idx = 2;
			multi_pipe(&info, ac, av, envp);
			dup2(info.file[0], STDIN_FILENO);
		}
		while (idx < ac - 2)
			f_process_mp(&info, av[idx++]);
		dup2(info.file[1], STDOUT_FILENO);
		execute_cmdline(&info, av[ac - 2]);
	}
	print_error("Form of command line is wrong", 0);
	return (0);
}
