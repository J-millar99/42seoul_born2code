/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:23:08 by jaehyji          ###   ########.fr       */
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

typedef struct s_cmd
{
	int		fd[2];
	int		file[2];
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**envp;
}	t_cmd;

/*			process			*/
void	c_process(t_cmd *info);
void	p_process(t_cmd *info);
void	f_process(pid_t child, t_cmd *info);

/*			utils			*/
void	malloc_free(t_cmd *info);
void	split_free(char **strarr);
void	parsing_cmdline(t_cmd *info, char **av, char **envp);
void	init_cmdinfo(t_cmd *info);
void	execute_cmdline(t_cmd *info, char **cmd);
void	open_close(t_cmd *info);

/*			check			*/
void	check_command(t_cmd *info);
char	*check_path(t_cmd *info, char *cmd);
void	check_some(char **paths, char **path, char **cmd_file, t_cmd *info);
char	**make_paths(t_cmd *info);
void	check_file(t_cmd *info);

/*			error			*/
void	print_error(char *error_string, t_cmd *info, int code);
void	print_error_cmd(char *cmd, int *flag);
void	print_error_nocmd(char *cmd, int *flag);
void	stop_flag(t_cmd *info, int flag);

#endif