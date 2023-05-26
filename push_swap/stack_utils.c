/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:18:24 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 15:04:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_node **lst, char **str)
{
	t_node	*node;

	while (*str != NULL)
	{
		node = lstnew(ft_atoi(*str));
		lstadd_back(lst, node);
		str++;
	}
	(*lst)->prev = lstlast(*lst);
	lstlast(*lst)->next = *lst;
}