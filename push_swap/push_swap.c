/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 13:11:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*lst;
	t_node			*node;

	str = input_check(ac, av);
	while (*str != NULL)
	{
		node = lstnew(ft_atoi(*str));
		lstadd_back(&lst, node);
		str++;
	}
	while (lst)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
	return (0);
}
