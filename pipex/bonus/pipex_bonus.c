/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/19 16:01:43 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **envp)
{
	t_cmdline	info;
	int			file[2];

	check_av(&info, ac, av, file);
	printf("%d %d\n", file[0], file[1]);
	if (!ft_strncmp(av[1], "here_doc", 8))
		printf("%d %d\n", file[0], file[1]);
	// 	//here_doc();
	// else
	// 	//multi_pipe();
	return (0);
}
