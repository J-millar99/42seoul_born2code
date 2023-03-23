/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:18 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/24 03:37:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	temp_lst = (t_list *)malloc(sizeof(t_list));
	if (temp_lst == NULL)
		return (NULL);
	start = temp_lst;
	while (lst->next != NULL)
	{
		temp_lst->next = (t_list *)malloc(sizeof(t_list));
		if (temp_lst->next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		temp_lst->content = (*f)(lst->content);
		temp_lst = temp_lst->next;
		lst = lst->next;
	}
	temp_lst->content = (*f)(lst->content);
	temp_lst->next = NULL;
	return (start);
}
