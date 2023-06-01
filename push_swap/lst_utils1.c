/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:20:01 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 12:48:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew(int num)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->value = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

t_node	*lstlast(t_node *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_node **lst, t_node *newnode)
{
	t_node	*temp_lst;

	if (*lst == NULL)
	{
		*lst = newnode;
		return ;
	}
	temp_lst = lstlast(*lst);
	temp_lst->next = newnode;
	newnode->prev = temp_lst;
}

void	lstclear(t_node **lst)
{
	t_node	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = (*lst)->next;
	while (temp != NULL)
	{
		free(*lst);
		*lst = temp;
		temp = (*lst)->next;
	}
	free(*lst);
	*lst = NULL;
}

int	lstsize(t_node *lst)
{
	int		size;
	int		value;

	if (!lst)
		return (0);
	size = 1;
	value = lst->value;
	while (lst->next)
	{
		lst = lst->next;
		if (value == lst->value)
			break ;
		size++;
	}
	return (size);
}
