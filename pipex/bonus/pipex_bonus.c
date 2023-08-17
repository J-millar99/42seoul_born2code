/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/09 17:10:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void f()
{
	system("leaks pipex");
}

int	main(int ac, char *av[], char **envp)
{
	t_cmd	info;
	int		idx;
	int		i;

	atexit(f);
	if (ac >= 5)
	{
		if (!ft_strcmp(av[1], "here_doc"))
		{
			idx = 3;
			here_doc(&info, ac, av, envp);
		}
		else
		{
			idx = 2;
			multi_pipe(&info, ac, av, envp);
			dup2(info.file[0], 0);
		}
		check_command(&info, av, idx, ac);
		i = idx;
		while (idx < ac - 2)
			c_process_mp(&info, av[idx++]);
		p_process_mp(&info, av[ac - 2], i, ac);
	}
	else
		print_error("Form of command line is wrong", NULL, 0);
	return (0);
}
