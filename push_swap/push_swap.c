/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 16:06:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*lst;

	str = input_check(ac, av);
	make_stack(&lst, str);
	rotate_reverse(&lst);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", lst->value);
		lst = lst->next;
	}
	return (0);
}
