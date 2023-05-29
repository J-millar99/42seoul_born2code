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

/*
	str은 이차원 문자배열이므로 1차, 2차 모두 free해줄 것.
*/

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*alst;
	static t_node	*blst;
	int		i = 0;

	str = input_check(ac, av);
	make_stack(&alst, str);
	if (!check_sorted(alst))
		printf("정렬이 안됨\n");

	return (0);
}

/*
	명령어 테스트케이스
	printf("===stack a===\n");
	while (alst && i < 7)
	{
		printf("%d\n", alst->value);
		alst = alst->next;
		i++;
	}
	i = 0;
	printf("===stack b===\n");
	while (blst && i < 7)
	{
		printf("%d\n", blst->value);
		blst = blst->next;
		i++;
	}
*/