/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:52:52 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/06 03:59:35 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_command_line(char ***env)
{
	char			*line;
	t_linked_list	*list;
	t_tree_node		*root;

	line = readline("minishell$ ");
	if (line)
	{
		add_history(line);
		list = lexer(line);
		if (list == 0)
			return (line);
		root = parser(list, *env);
		if (root == 0)
			return (line);
		free_list(list, 0);
		run_root(root, env);
		free_tree(root, 1);
	}
	else
		shell_ctrl_d();
	return (line);
}

int	main()
{
	char	**env;
	char	*line;
	int		o_fd[2];

	env = init_setting(environ, o_fd);
	while (1)
	{
		set_shell_signal();
		line = read_command_line(&env);
		if (line)
			free(line);
		else
			break ;
		recover_std_fd(o_fd);
	}
	return (0);
}
