/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:08 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 13:28:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *error_strting, t_cmdline *info)
{
	perror(error_strting);
	malloc_free(info);
	exit(EXIT_FAILURE);
}
