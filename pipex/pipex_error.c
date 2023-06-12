/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 20:27:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	malloc_error(t_cmdline *info)
{
	malloc_free(info);
	print_error("Malloc Function Error");
}

void	print_error(char *error_strting)
{
	perror(error_strting);
	exit(EXIT_FAILURE);
}

void	check_command(t_cmdline *info)
{
	if (info->cmd1 )

	if (info->cmd2)
		print_error("Command is wrong");
}

void	check_file(t_cmdline *info)
{
	if (access(info->infile) == -1)
		print_error("Infile does not exist");
}