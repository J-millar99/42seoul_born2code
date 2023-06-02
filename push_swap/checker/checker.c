/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:19:26 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 16:11:52 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/mandatory/includes/get_next_line.h"

int	main(int ac, char *av[])
{
	char			**str;
	static t_node	*alst;
	static t_node	*blst;

	str = input_check(ac, av);
	make_stack(&alst, str);
	if (check_sorted(alst))
		ft_printf("Stack A already is aligned\n");
	else
		read_standard_input(&alst, &blst);
	return (0);
}

void	read_standard_input(t_node **alst, t_node **blst)
{
	char	*command_line;

	command_line = get_next_line(0);
	if (!command_line || !*command_line)
		print_error();
	execute_command_line(alst, blst, command_line);
	if (!check_sorted(*alst))
		ft_printf("1KO\n");
	else if (*blst)
		ft_printf("2KO\n");
	else
		ft_printf("OK\n");
}

void	execute_command_line(t_node **alst, t_node **blst, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_command_line(alst, blst, line);
		free(tmp);
	}
}

char	*check_command_line(t_node **alst, t_node **blst, char *line)
{
	char	command_type;

	command_type = line[0];
	printf("%c", command_type);
	if (command_type == 'p')
		push_command(alst, blst, line);
	else if (command_type == 's')
		swap_command(alst, blst, line);
	else if (command_type == 'r')
		rotate_command(alst, blst, line);
	else
		print_error();
	return (get_next_line(0));
}
