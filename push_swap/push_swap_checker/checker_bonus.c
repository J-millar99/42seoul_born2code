/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:19:26 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/16 18:32:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/includes/get_next_line.h"

int	main(int ac, char *av[])
{
	char	**str;
	t_node	*alst;
	t_node	*blst;

	alst = NULL;
	blst = NULL;
	str = input_check(ac, av);
	make_stack(&alst, str);
	read_standard_input(&alst, &blst);
	clear_all(&alst, str);
	return (0);
}

void	read_standard_input(t_node **alst, t_node **blst)
{
	char	*command_line;

	command_line = get_next_line(0);
	execute_command_line(alst, blst, command_line);
	if (!check_sorted(*alst))
		write(1, "KO\n", 3);
	else if (*blst)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	execute_command_line(t_node **alst, t_node **blst, char *line)
{
	char	*tmp;

	while (line && *line)
	{
		tmp = line;
		line = check_command_line(alst, blst, line);
		free(tmp);
	}
	free(line);
}

char	*check_command_line(t_node **alst, t_node **blst, char *line)
{
	char	command_type;

	command_type = line[0];
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
