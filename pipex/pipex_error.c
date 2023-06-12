/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 20:00:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	malloc_free(t_cmdline *info)
{
	if (info->infile)
		free(info->infile);
	if (info->cmd1)
		free(info->cmd1);
	if (info->cmd2)
		free(info->cmd2);
	if (info->outfile)
		free(info->outfile);
	print_error("malloc error");
}

void	print_error(char *error_strting)
{
	perror(error_strting);
	exit(EXIT_FAILURE);
}
