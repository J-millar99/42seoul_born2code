/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:06:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **envp)
{
	pid_t	child;
	t_cmd	info;

	if (ac == 5)
	{
		init_cmdinfo(&info);
		parsing_cmdline(&info, av, envp);
		check_file(&info);
		check_command(&info);
		if (pipe(info.fd) == -1)
			print_error("pipe", &info, 1);
		child = fork();
		if (child == -1)
			print_error("fork", &info, 1);
		f_process(child, &info);
	}
	else
		print_error("Form of command line is wrong", NULL, 0);
	return (0);
}
