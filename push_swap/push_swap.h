/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:36 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 16:06:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/bonus/includes/ft_printf_bonus.h"
# include "libft/mandatory/includes/libft.h"
# include "libft/mandatory/includes/libft_bonus.h"
# include <stdio.h>

typedef struct s_node
{
	int		value;
	void	*prev;
	void	*next;
}	t_node;

/*		lst		*/
t_node	*lstnew(int num);
t_node	*lstlast(t_node *lst);
void	lstadd_back(t_node **lst, t_node *newnode);
void	lstclear(t_node **lst);

/*		stack		*/
void	make_stack(t_node **lst, char **str);
void	process(t_node **bot, t_node **top);
void	put_on(t_node **bot, t_node **top);

/*		error		*/
char	*make_str(int ac, char *av[]);
void	print_error(void);
int		ft_strcmp(const char *x, const char *y);
char	**input_check(int ac, char *av[]);
int		check_sorted(t_node *lst);
void	free_split(char **str);

/*		algorithm		*/
void	swap(t_node **lst);
void	push(t_node **bot, t_node **top);
void	rotate(t_node **lst);
void	rotate_reverse(t_node **lst);

#endif