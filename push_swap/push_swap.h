/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:36 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/05 13:34:47 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
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
int		lstsize(t_node *lst);
t_node	*bi_lstlast(t_node *lst);
int		lst_min(t_node *lst);
int		lst_max(t_node *lst);

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

/*		command		*/
void	swap_a(t_node **alst);
void	swap_b(t_node **blst);
void	swap_swap(t_node **alst, t_node **blst);
void	push_a(t_node **alst, t_node **blst);
void	push_b(t_node **blst, t_node **alst);
void	rotate_a(t_node **alst);
void	rotate_b(t_node **blst);
void	rotate_rotate(t_node **alst, t_node **blst);
void	rotate_reverse_a(t_node **alst);
void	rotate_reverse_b(t_node **blst);
void	rotate_rotate_reverse(t_node **alst, t_node **blst);

/*		algorithm		*/
void	sort_algorithm(t_node **alst);
t_node	*setting_blst(t_node **alst);
t_node	**setting_alst(t_node **alst, t_node **blst);
void	sort_remaining_alst3(t_node **alst);
void	operate_remaining_alst3(t_node **blst, t_node **alst);

/*		rotate_case		*/
int		case_rarb_atob(t_node *alst, t_node *blst, int value);
int		case_rrarrb_atob(t_node *alst, t_node *blst, int value);
int		case_rarrb_atob(t_node *alst, t_node *blst, int value);
int		case_rrarb_atob(t_node *alst, t_node *blst, int value);
int		case_rarb_btoa(t_node *alst, t_node *blst, int value);
int		case_rrarrb_btoa(t_node *alst, t_node *blst, int value);
int		case_rarrb_btoa(t_node *alst, t_node *blst, int value);
int		case_rrarb_btoa(t_node *alst, t_node *blst, int value);

/*		search		*/
int		find_idx(t_node *lst, int value);
int		find_right_place_alst(t_node *alst, int value);
int		find_right_place_blst(t_node *blst, int value);

/*		check_rotate_type		*/
int		check_rotate_type_atob(t_node *alst, t_node *blst);
int		check_rotate_type_btoa(t_node *alst, t_node *blst);

/*		rotate_push		*/
int		rarb_push(t_node **alst, t_node **blst, int value, char lst);
int		rrarrb_push(t_node **alst, t_node **blst, int value, char lst);
int		rarrb_push(t_node **alst, t_node **blst, int value, char lst);
int		rrarb_push(t_node **alst, t_node **blst, int value, char lst);

/*		checker		*/
void	read_standard_input(t_node **alst, t_node **blst);
char	*check_command_line(t_node **alst, t_node **blst, char *line);
void	execute_command_line(t_node **alst, t_node **blst, char *line);
void	push_command(t_node **alst, t_node **blst, char *command);
void	swap_command(t_node **alst, t_node **blst, char *command);
void	rotate_command(t_node **alst, t_node **blst, char *command);

#endif