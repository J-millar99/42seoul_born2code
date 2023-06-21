/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:57 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 17:44:35 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int ac, char **av, char **envp)
{
	t_hd	info;

	check_hd(&info, ac, av, envp);
}

void	execute_cmd_hd(char **av)
{
	char	*limiter;
	char	*line;
	char	*tmp;

	limiter = av[1];
	line = get_next_line(0);
	while (1)
	{
		if (!ft_strncmp(limiter, line, ft_strlen(line) - 1))
			break ;
		tmp = line;
		line = get_next_line(0);
		free(tmp);
	}
}