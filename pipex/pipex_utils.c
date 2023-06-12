/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:02 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 19:59:22 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_cmd(t_cmdline *info, char **av, char **envp)
{
	info->envp = envp;
	info->infile = ft_strdup(av[1]);
	info->cmd1 = ft_split(av[2], ' ');
	info->cmd2 = ft_split(av[3], ' ');
	info->outfile = ft_strdup(av[4]);
	if (!info->infile || !info->cmd1 || !info->cmd2 || !info->outfile)
		malloc_free(info);
}
