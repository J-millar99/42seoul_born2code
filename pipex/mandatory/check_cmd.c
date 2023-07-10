/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:52:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/10 19:36:00 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command(t_cmd *info)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = check_path(info, info->cmd1[0]);
	if (!cmd1)
		print_error(info->cmd1[0], info, 1);
	cmd2 = check_path(info, info->cmd2[0]);
	if (!cmd2)
	{
		free(cmd1);
		print_error(info->cmd2[0], info, 1);
	}
	free(cmd1);
	free(cmd2);
}
