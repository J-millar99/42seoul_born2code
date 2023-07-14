/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:33:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:33:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error_cmd(char *cmd, int *flag)
{
	write(1, "pipex: ", 8);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, ": ", 2);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	*flag = 1;
}

void	print_error_nocmd(char *cmd, int *flag)
{
	write(1, "pipex: ", 8);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	*flag = 1;
}

void	print_error(char *error_string, t_cmd *info, int code)
{
	write(1, "pipex: ", 8);
	if (code)
	{
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, ": ", 2);
	}
	write(1, error_string, ft_strlen(error_string));
	write(1, "\n", 1);
	open_close(info);
	exit(EXIT_FAILURE);
}
