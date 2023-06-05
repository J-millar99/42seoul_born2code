/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/05 16:15:59 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*alst;
	static t_node	*blst;

	str = input_check(ac, av);
	make_stack(&alst, str);
	push_b(&blst, &alst);
	rotate_a(&alst);
	swap_a(&alst);
	rotate_reverse_a(&alst);
	push_a(&alst, &blst);
	rotate_reverse_a(&alst);
	rotate_reverse_a(&alst);
	printf("===stack a===\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", alst->value);
		if (alst->next)
			alst = alst->next;
	}
	printf("===stack b===\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", blst->value);
		if (blst->next)
			blst = blst->next;
	}
	exit (0);
	if (!check_sorted(alst))
		sort_algorithm(&alst);
	return (0);
}
