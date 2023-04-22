/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:52:48 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/21 14:52:48 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
	head는 list의 시작지점
	find는 찾으려는 해당 fd 리스트
	list를 탐색하다가 fd가 나오면 find를 반환
	못찾았다면 해당 fd로 새로운 노드를 생성하고 next_fd에 저장
	마지막으로 list를 초기 위치로 되돌려 재탐색 준비
*/

t_list	*find_fd_list(t_list **list, int fd)
{
	t_list	*find;
	t_list	*head;

	head = *list;
	if (!*list)
	{
		*list = new_list(fd);
		return (*list);
	}
	while ((*list)->next_fd && (*list)->fd != fd)
		*list = (*list)->next_fd;
	if ((*list)->fd == fd)
		find = *list;
	else
	{
		find = new_list(fd);
		if (!find)
			return (NULL);
		(*list)->next_fd = find;
	}
	*list = head;
	return (find);
}

t_list	*new_list(int fd)
{
	t_list	*node;

	if (fd < 0)
		return (NULL);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->backup = NULL;
	node->next_fd = NULL;
	return (node);
}

int	return_char_idx(char *str, int flag)
{
	int		i;

	i = 0;
	if (flag)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i);
		return (-1);
	}
	else
	{
		while (str[i])
			i++;
		return (i);
	}
}

void	node_strjoin(t_list *node, char *buff, int rbyte)
{
	char	*result;
	int		i;
	int		prev_len;

	prev_len = 0;
	if (node->backup)
		while ((node->backup)[prev_len])
			prev_len++;
	result = (char *)malloc(prev_len + rbyte + 1);
	if (!result)
		return ;
	i = -1;
	while (++i < prev_len)
		result[i] = (node->backup)[i];
	i = -1;
	while (++i < rbyte)
		result[prev_len + i] = buff[i];
	result[prev_len + rbyte] = '\0';
	free(node->backup);
	node->backup = result;
}

char	*ft_substr(char *backup, int start, int len)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = backup[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
