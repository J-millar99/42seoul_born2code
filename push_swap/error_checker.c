/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:36:11 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 13:11:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_integer(char **str_array)
{
	int		flag;

	flag = 1;
	while (*str_array)
	{
		ft_atoi_flag(*str_array, &flag);
		if (!flag)
			print_error();
		str_array++;
	}
}

void	duplicate_check(char **str_array)
{
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		j = i + 1;
		while (1)
		{
			if (!str_array[j])
				break ;
			if (ft_strcmp(str_array[i], str_array[j]) == 0)
				print_error();
			j++;
		}
		i++;
		if (!str_array[i])
			break ;
	}
}

char	**input_check(int ac, char *av[])
{
	char	**str_array;
	char	*array_oneline;
	int		i;

	i = 1;
	if (ac < 2)
		print_error();
	while (i < ac)
	{
		while ((*(av[i]) == 32 || (9 <= *(av[i]) && *(av[i]) <= 13)))
			av[i]++;
		if (!*av[i])
			print_error();
		i++;
	}
	array_oneline = make_str(ac, av);
	str_array = ft_split(array_oneline, ' ');
	free(array_oneline);
	if (!str_array)
		print_error();
	check_integer(str_array);
	duplicate_check(str_array);
	return (str_array);
}
