/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:18:24 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 18:20:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_node **lst, char **str)
{
	t_node	*node;

	while (*str != NULL)
	{
		node = lstnew(ft_atoi(*str));
		if (node == NULL)
		{
			free_split(str);
			if (*lst)
				lstclear(lst);
			print_error();
		}
		lstadd_back(lst, node);
		str++;
	}
	(*lst)->prev = lstlast(*lst);
	lstlast(*lst)->next = *lst;
}

void	process(t_node **bot, t_node **top)
{
	t_node	*top_snode;
	t_node	*top_lnode;
	int		topsize;

	topsize = lstsize(*top);
	top_snode = (*top)->next;
	top_lnode = (*top)->prev;
	(*top)->next = NULL;
	(*top)->prev = NULL;
	if (topsize == 2)
	{
		top_snode->prev = NULL;
		top_lnode->next = NULL;
	}
	else if (topsize > 2)
	{
		top_snode->prev = top_lnode;
		top_lnode->next = top_snode;
	}
	put_on(bot, top);
	*top = top_snode;
}

void	put_on(t_node **bot, t_node **top)
{
	t_node	*bot_lnode;
	int		botsize;

	botsize = lstsize(*bot);
	if (botsize > 0)
	{
		bot_lnode = (*bot)->prev;
		if (botsize == 1)
		{
			(*bot)->prev = *top;
			(*bot)->next = *top;
			(*top)->prev = *bot;
			(*top)->next = *bot;
		}
		else
		{
			(*top)->prev = (*bot)->prev;
			(*top)->next = *bot;
			(*bot)->prev = *top;
			bot_lnode->next = *top;
		}
	}
	*bot = *top;
}
