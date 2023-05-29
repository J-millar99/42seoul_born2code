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

void	check_novalue(int ac, char *av[])
{
	int		i;

	i = 1;
	while (i < ac)
	{
		while ((*(av[i]) == 32 || (9 <= *(av[i]) && *(av[i]) <= 13)))
			*av[i]++;
		if (!*av[i])
			print_error();
		i++;
	}
}

int	check_integer(char **str_array)
{
	int		flag;

	flag = 1;
	while (*str_array)
	{
		ft_atoi_flag(*str_array, &flag);
		if (!flag)
			return (0);
		str_array++;
	}
	return (1);
}

int	duplicate_check(char **str_array)
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
				return (0);
			j++;
		}
		i++;
		if (!str_array[i])
			break ;
	}
	return (1);
}

char	**input_check(int ac, char *av[])
{
	char	**str_array;
	char	*array_oneline;

	if (ac < 2)
		print_error();
	check_novalue(ac, av);
	array_oneline = make_str(ac, av);
	str_array = ft_split(array_oneline, ' ');
	free(array_oneline);
	if (!str_array)
		print_error();
	if (!check_integer(str_array) || !duplicate_check(str_array))
	{
		free_split(str_array);
		print_error();
	}
	return (str_array);
}

int	check_sorted(t_node *lst)
{
	int		min;
	t_node	*lnode;

	lnode = lst->prev;
	min = lst->value;
	while (1)
	{
		if (min > lst->value)
			return (0);
		min = lst->value;
		lst = lst->next;
		if (lst == lnode)
		{
			if (min > lst->value)
				return (0);
			break;
		}
	}
	return (1);
}
