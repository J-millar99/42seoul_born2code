/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:32:22 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/26 23:38:51 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *estr, int code, t_file *info)
{
	if (code)
	{
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, ": ", 2);
	}
	if (info->fd)
		close(info->fd);
	write(1, estr, ft_strlen(estr));
	write(1, "\n", 1);
	exit(1);
}
