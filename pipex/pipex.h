/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/15 14:22:21 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_cmdline
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**envp;

}	t_cmdline;

/*			process			*/
void	c_process(t_cmdline *info, int *fd);
void	p_process(t_cmdline *info, int *fd);

/*			utils			*/
void	malloc_free(t_cmdline *info);
void	split_free(char **strarr);
void	parsing_cmdline(t_cmdline *info, char **av, char **envp);
void	init_cmdinfo(t_cmdline *info);
void	execute_cmdline(t_cmdline *info, char **cmd);

/*			check			*/
void	check_command(t_cmdline *info);
char	*check_path(t_cmdline *info, char *cmd);
void	check_infile(t_cmdline *info);
void	check_some(char **paths, char **path, char **cmd_file, t_cmdline *info);
char	**make_paths(t_cmdline *info);

/*			error			*/
void	print_error(char *error_strting, t_cmdline *info);
void	check_error(t_cmdline *info);

#endif