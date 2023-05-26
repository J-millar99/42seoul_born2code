/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:36 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 11:50:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/bonus/includes/ft_printf_bonus.h"
# include "libft/mandatory/includes/libft.h"
# include "libft/mandatory/includes/libft_bonus.h"

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

/*		error		*/
char	*make_str(int ac, char *av[]);
void	print_error(void);
int		ft_strcmp(const char *x, const char *y);
char	**input_check(int ac, char *av[]);

#endif