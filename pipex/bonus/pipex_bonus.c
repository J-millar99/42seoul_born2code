/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 13:52:39 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **envp)
{
	if (ac == 1)
		print_error("Form of command line is wrong", NULL, 0);
	if (!ft_strcmp(av[1], "here_doc"))
		here_doc(ac, av + 1, envp);
	// else
	// 	multi_pipe(ac, av, envp);
	return (0);
}