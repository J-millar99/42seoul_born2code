/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:28 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/30 14:31:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	str은 이차원 문자배열이므로 1차, 2차 모두 free해줄 것.
*/

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*alst;

	str = input_check(ac, av);
	make_stack(&alst, str);
	if (!check_sorted(alst))
		sort_algorithm(&alst);
	return (0);
}

/*
	명령어 테스트케이스
	printf("===stack a===\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", alst->value);
		alst = alst->next;
	}
	i = 0;
	printf("===stack b===\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", blst->value);
		blst = blst->next;
	}
*/