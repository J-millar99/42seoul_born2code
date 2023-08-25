/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:03:29 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 19:33:10 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elemnet;

	new_elemnet = (t_list *)malloc(sizeof(t_list));
	if (new_elemnet == NULL)
		return (NULL);
	new_elemnet->content = content;
	(*new_elemnet).next = NULL;
	return (new_elemnet);
}
