/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 18:51:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **envp)
{
	pid_t	child;
	t_cmd	info;

	if (ac == 5)
	{
		check_argv(&info, ac, av);
		parsing_cmdline(&info, av, envp);
		check_file(&info);
		if (pipe(info.fd) == -1)
			print_error("Pipe Function Error", &info, 1);
		child = fork();
		if (child == -1)
			print_error("Fork Function Error", &info, 1);
		f_process(child, &info);
	}
	else
		print_error("Form of command line is wrong", NULL, 0);
	return (0);
}
