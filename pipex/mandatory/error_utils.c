/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:08 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 15:19:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *error_string, t_cmd *info, int code)
{
	if (code)
		perror(error_string);
	else
		write(1, error_string, ft_strlen(error_string));
	malloc_free(info);
	exit(EXIT_FAILURE);
}
