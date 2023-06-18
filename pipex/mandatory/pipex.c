/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 17:14:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **envp)
{
	int			fd[2];
	int			file[2];
	pid_t		child;
	t_cmdline	info;

	check_av(&info, ac, av);
	if (ac == 5)
	{
		parsing_cmdline(&info, av, envp);
		check_file(&info, file);
		if (pipe(fd) == -1)
			print_error("Pipe Function Error", &info);
		child = fork();
		if (child == -1)
			print_error("Fork Function Error", &info);
		f_process(child, &info, fd, file);
	}
	else
		print_error("Form of command line is wrong", &info);
	return (0);
}
