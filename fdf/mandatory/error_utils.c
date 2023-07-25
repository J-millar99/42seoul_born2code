/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:32:22 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 18:53:48 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *estr, int code)
{
	if (code)
	{
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, ": ", 2);
	}
	write(1, estr, ft_strlen(estr));
	write(1, "\n", 1);
	exit(1);
}

void	free_arr(char **arr)
{
	int		idx;

	if (!arr)
		print_error("ft_split", 1);
	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		++idx;
	}
	free(arr);
}
