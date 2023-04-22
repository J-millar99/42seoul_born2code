/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:50:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/21 14:50:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*rstr;
	char			*buff;
	t_list			*node;
	static t_list	*list;

	node = find_fd_list(&list, fd);
	if (!node)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rstr = read_file(node, &buff);
	if (!rstr)
		del_fd_list(&list, node);
	return (rstr);
}

char	*read_file(t_list *node, char **buff)
{
	int		rbyte;

	rbyte = 1;
	while (rbyte > 0)
	{
		rbyte = read(node->fd, *buff, BUFFER_SIZE);
		if (rbyte <= 0)
			break ;
		(*buff)[BUFFER_SIZE] = '\0';
		node_strjoin(node, *buff, rbyte);
		if (return_char_idx(node->backup, 1) >= 0)
			break ;
	}
	free(*buff);
	if (node->backup && rbyte >= 0)
		return (make_oneline(node));
	return (NULL);
}

/*
	한줄이 완성되는 경우는 줄바꿈이 존재하거나
	마지막 글자를 읽었을 때 반환
*/

char	*make_oneline(t_list *node)
{
	int		nl;
	int		end;
	char	*str_to_return;
	char	*remaining_str;

	nl = return_char_idx(node->backup, 1);
	end = return_char_idx(node->backup, 0);
	if (end - nl == 1 || nl < 0)
	{
		str_to_return = ft_substr(node->backup, 0, end);
		remaining_str = NULL;
	}
	else
	{
		str_to_return = ft_substr(node->backup, 0, nl + 1);
		remaining_str = ft_substr(node->backup, nl + 1, end - nl - 1);
		if (!remaining_str)
			return (NULL);
	}
	if (!str_to_return)
		return (NULL);
	free(node->backup);
	node->backup = remaining_str;
	return (str_to_return);
}

void	free_node(t_list *node)
{
	free(node->backup);
	node->backup = NULL;
	free(node);
	node = NULL;
}

void	del_fd_list(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*find;

	prev = *lst;
	while (prev->next_fd != node && prev != node)
		prev = prev->next_fd;
	if (prev == node)
	{
		*lst = prev->next_fd;
		free_node(prev);
	}
	else
	{
		find = prev->next_fd;
		prev->next_fd = find->next_fd;
		free_node(find);
	}
}
