/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:53:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 17:17:10 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*bi_lstlast(t_node *lst)
{
	if (lstsize(lst) < 2)
		return (lst);
	return (lst->prev);
}

int	lst_min(t_node *lst)
{
	int		min;
	int		lsize;

	lsize = lstsize(lst);
	min = lst->value;
	while (lsize--)
	{
		lst = lst->next;
		if (lst->value < min)
			min = lst->value;
	}
	return (min);
}

int	lst_max(t_node *lst)
{
	int		max;
	int		lsize;

	lsize = lstsize(lst);
	max = lst->value;
	while (lsize--)
	{
		lst = lst->next;
		if (lst->value > max)
			max = lst->value;
	}
	return (max);
}
