/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:51:50 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/23 08:56:28 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next_fd;
}	t_list;

char	*get_next_line(int fd);
char	*read_file(t_list *node, char **buff);
char	*make_oneline(t_list *node);
void	free_node(t_list *node);
t_list	*find_fd_list(t_list **list, int fd);
void	del_fd_list(t_list **list, t_list *node);
t_list	*new_list(int fd);
int		return_char_idx(char *str, int flag);
void	node_strjoin(t_list *node, char *buff, int byte);
char	*ft_substr(char *backup, int start, int len);
char	*make_oneline(t_list *node);

#endif