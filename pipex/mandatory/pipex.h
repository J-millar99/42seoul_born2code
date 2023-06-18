/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 17:39:45 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
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
void	c_process(t_cmdline *info, int *fd, int infile);
void	p_process(t_cmdline *info, int *fd, int outfile);
void	f_process(pid_t child, t_cmdline *info, int *fd, int *file);

/*			utils			*/
void	malloc_free(t_cmdline *info);
void	split_free(char **strarr);
void	parsing_cmdline(t_cmdline *info, char **av, char **envp);
void	init_cmdinfo(t_cmdline *info);
void	execute_cmdline(t_cmdline *info, char **cmd);

/*			check			*/
void	check_command(t_cmdline *info);
char	*check_path(t_cmdline *info, char *cmd);
void	check_some(char **paths, char **path, char **cmd_file, t_cmdline *info);
char	**make_paths(t_cmdline *info);
void	check_av(t_cmdline *info, int ac, char **av);
void	check_file(t_cmdline *info, int *file);

/*			error			*/
void	print_error(char *error_strting, t_cmdline *info);

#endif