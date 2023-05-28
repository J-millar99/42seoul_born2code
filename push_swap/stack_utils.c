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

void	process_top(t_node **bot, t_node **top)
{
	t_node	*top_lastnode;
	t_node	*top_secondnode;

	if ((*top)->prev == NULL || (*top)->next == NULL)
		return ;
	top_secondnode = (*top)->next;
	top_lastnode =  (*top)->prev;
	top_secondnode->prev = top_lastnode;
	top_lastnode->next = top_secondnode;
	top = top_secondnode;
}

void	process_bot(t_node **bot, t_node **top)
{
	t_node	*bot_lastnode;
	t_node	*bot_secondnode;

	if (bot == NULL)
	{
		(*top)->prev = NULL;
		(*top)->next = NULL;
	}
	bot_secondnode = (*bot)->next;
	bot_lastnode = (*bot)->prev;
	if (bot_secondnode == NULL || bot_lastnode == NULL)
	{

	}
	bot_secondnode->prev = *top;
	bot_lastnode->next = *top;
	(*top)->prev = (*bot)->prev;
	(*top)->next = (*bot)->next;
	*bot = *top;
}
