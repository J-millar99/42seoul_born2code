/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/19 16:56:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **envp)
{
	t_cmd	info;

	if (ac != 5)
		print_error("Form of command line is wrong", NULL, 0);
	setting_cmdinfo(&info, av, envp);
	check_commandline(&info, av);
	check_file(&info);
	f_process1(&info, av);
	return (0);
}
