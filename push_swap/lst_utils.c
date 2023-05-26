/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:20:01 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 14:47:12 by jaehyji          ###   ########.fr       */
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

	if (newnode == NULL)
	{
		lstclear(lst);
		print_error();
	}
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
