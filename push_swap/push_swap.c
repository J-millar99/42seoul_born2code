/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/16 18:32:27 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	**str;
	t_node	*alst;

	alst = NULL;
	if (ac == 1)
		exit(0);
	str = input_check(ac, av);
	make_stack(&alst, str);
	if (!check_sorted(alst))
		sort_algorithm(&alst);
	clear_all(&alst, str);
	return (0);
}
