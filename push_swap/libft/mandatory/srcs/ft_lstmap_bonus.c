/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:03:26 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 02:03:26 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tlst;
	t_list	*start;
	void	*tcontent;

	if (lst == NULL)
		return (NULL);
	start = NULL;
	while (lst)
	{
		tcontent = f(lst->content);
		tlst = ft_lstnew(tcontent);
		if (tlst == NULL)
		{
			del(tcontent);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, tlst);
		tlst = tlst->next;
		lst = lst->next;
	}
	return (start);
}
