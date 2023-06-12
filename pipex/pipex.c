/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 20:26:52 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	pipe()
	fd[0]: 읽기 전용 파일 디스크립터
	fd[1]: 쓰기 전용 파일 디스크립터

	fork()
	프로세스를 복사
	복사된 프로세스는 자식 프로세스

*/

int	main(int ac, char *av[], char **envp)
{
	int			fd[2];
	pid_t		child;
	t_cmdline	cmdline;

	parsing_cmd(&cmdline, av, envp);
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			print_error("Pipe Function Error");
		child = fork();
		if (child == -1)
			print_error("Fork Function Error");
		if (child == 0)
			printf("2\n");
		else
			printf("1\n");
	}
	else
		print_error("Form of command line is wrong");
	return (0);
}
