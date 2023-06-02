/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:59:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 14:48:24 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*make_str(int ac, char *av[])
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strdup(av[1]);
	if (!str)
		print_error();
	i = 2;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(str, av[i]);
		if (!str)
		{
			free(tmp);
			print_error();
		}
		i++;
		free(tmp);
	}
	return (str);
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_strcmp(const char *x, const char *y)
{
	while (*x)
	{
		if (*x != *y)
			break ;
		x++;
		y++;
	}
	return (*(const unsigned char *)x - *(const unsigned char *)y);
}

void	free_split(char **str)
{
	void	**tmp;

	tmp = (void **)str;
	while (*str != NULL)
	{
		free(*str);
		str++;
	}
	free(tmp);
}
