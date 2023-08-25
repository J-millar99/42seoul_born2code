/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:31:08 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/25 12:11:32 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	char	*line;

	while (1)
	{
		line = readline("minishell-1.0$ ");
		if (!line)
			exit(0);
		add_history(line);
		printf("%s\n", line);
		free(line);
	}
}
