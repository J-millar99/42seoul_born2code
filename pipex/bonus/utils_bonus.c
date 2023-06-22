/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:12:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 12:05:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	split_free(char **strarr)
{
	int		idx;

	idx = 0;
	while (strarr[idx])
	{
		free(strarr[idx]);
		++idx;
	}
	free(strarr);
}

void	print_error(char *error_string)
{
	write(1, error_string, ft_strlen(error_string));
	exit(EXIT_FAILURE);
}
