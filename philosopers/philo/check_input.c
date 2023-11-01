/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/02 05:22:24 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	make_system_info(int *arr, char **line_arr)
{
	int		idx;
	int		num;
	int		flag;

	flag = 0;
	idx = 0;
	while (line_arr[idx])
	{
		num = ft_atoi(line_arr[idx]);
		if (num < 0)
			flag = 1;
		arr[idx] = num;
		idx++;
	}
	idx = 0;
	while (idx < 4)
	{
		if (arr[idx] == 0)
			flag = 1;
		idx++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	check_input(int argc, char **argv, int *arr)
{
	int		cnt;
	char	*line;
	char	**line_arr;

	line = make_str(argc, argv);
	if (!line)
		return (0);
	line_arr = ft_split(line, ' ');
	free_str(line);
	if (!line_arr)
		return (0);
	cnt = cnt_arr(line_arr);
	if (cnt != 4 && cnt != 5)
		return (0);
	return (make_system_info(arr, line_arr));
}
