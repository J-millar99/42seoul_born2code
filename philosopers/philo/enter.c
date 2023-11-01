/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/02 05:56:17 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	enter(t_id **lst, int max)
{
	t_id	*node;
	int		i;

	i = 1;
	*lst = NULL;
	while (i <= max)
	{
		node = lstnew();
		if (node == NULL)
		{
			if (*lst)
				lstclear(*lst);
			return (0);
		}
		node->idx = i;
		lstadd_back(lst, node);
		i++;
	}
	(*lst)->prev = lstlast(*lst);
	lstlast(*lst)->next = *lst;
	return (1);
}

t_id	*lstnew(void)
{
	t_id	*man;

	man = (t_id *)malloc(sizeof(t_id));
	if (!man)
		return (NULL);
	man->eat_num = 0;
	man->eat_time = 0;
	man->left = 0;
	man->right = 0;
	man->prev = NULL;
	man->next = NULL;
	return (man);
}

t_id	*lstlast(t_id *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_id **lst, t_id *newnode)
{
	t_id	*temp_lst;

	if (*lst == NULL)
	{
		*lst = newnode;
		return ;
	}
	temp_lst = lstlast(*lst);
	temp_lst->next = newnode;
	newnode->prev = temp_lst;
}
