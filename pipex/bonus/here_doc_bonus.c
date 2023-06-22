/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 14:43:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int ac, char **av, char **envp)
{
	t_hd	info;
	int		fd[2];
	pid_t	child;
	int		file;

	check_hd(&info, ac, av, envp);
	if (pipe(fd) == -1)
		print_error_hd("Pipe Function Error", &info, 1);
	child = fork();
	if (child == -1)
		print_error_hd("Fork Function Error", &info, 1);
	f_process_fd(child, &info, fd);
}
