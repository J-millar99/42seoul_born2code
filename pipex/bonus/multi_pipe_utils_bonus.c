/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:28:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 18:33:26 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_mp(t_cmd *info, int ac, char **av, char **envp)
{
	int		lidx;

	info->envp = envp;
	info->outfile = av[5];
	info->limiter = av[2];
	lidx = ft_strlen(av[3]) - 1;
	if (*(av[3]) == 32 || (9 <= *(av[3]) && *(av[3]) <= 13))
		print_error("Command is wrong", 0);
	if (av[3][lidx] == 32 || (9 <= av[3][lidx] && av[3][lidx] <= 13))
		print_error("Command is wrong", 0);
	lidx = ft_strlen(av[4]) - 1;
	if (*(av[4]) == 32 || (9 <= *(av[4]) && *(av[4]) <= 13))
		print_error("Command is wrong", 0);
	if (av[4][lidx] == 32 || (9 <= av[4][lidx] && av[4][lidx] <= 13))
		print_error("Command is wrong", 0);
}
