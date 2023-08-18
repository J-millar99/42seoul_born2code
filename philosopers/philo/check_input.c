/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/18 17:49:30 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > INT_MAX || (*str && !('0' <= *str && *str <= '9')))
		return (0);
	return (num);
}

char	*make_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;

	if (!*av)
		return (NULL);
	str = ft_strdup(av[0]);
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac - 1)
	{
		tmp = str;
		str = ft_strspacejoin(str, av[i]);
		if (!str)
			return (free(tmp), NULL);
		i++;
		free(tmp);
	}
	return (str);
}

int	check_input(int argc, char **argv, int *arr)
{
	int		i;
	int		num;
	char	*line;
	char	**line_arr;

	line = make_str(argc, argv);
	if (!line)
		return (0);
	line_arr = ft_split(line, ' ');
	free(line);
	if (!line_arr)
		return (0);
	i = 0;
	while (line_arr[i])
	{
		num = ft_atoi(line_arr[i]);
		if (num == 0 || i == 5)
			break ;
		arr[i] = num;
		i++;
	}
	if (i < 3 || line_arr[i])
		return (split_free(line_arr), 0);
	return (split_free(line_arr), 1);
}
