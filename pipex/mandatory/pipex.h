/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/19 16:50:34 by jaehyji          ###   ########.fr       */
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
	int		file[2];
	char	*infile;
	char	*outfile;
	char	**envp;
}	t_cmd;

/*			process			*/
void	f_process1(t_cmd *info, char **av);
void	f_process2(t_cmd *info, char **av, int *fd);
void	f_process3(t_cmd *info, int *fd);
/*			utils			*/
void	split_free(char **strarr);
void	setting_cmdinfo(t_cmd *info, char **av, char **envp);
void	init_cmdinfo(t_cmd *info);
void	execute_cmdline(t_cmd *info, char *av);
void	open_close(t_cmd *info);

/*			check			*/
void	check_command(t_cmd *info, char *av);
void	check_commandline(t_cmd *info, char *av[]);
char	*check_path(t_cmd *info, char *cmd);
void	check_some(char **paths, char **path, char **cmd_file, t_cmd *info);
char	**make_paths(t_cmd *info);
void	check_file(t_cmd *info);

/*			error			*/
void	print_error(char *error_string, t_cmd *info, int code);
void	print_error_cmd1(char *str);
void	print_error_cmd2(char *str, char *cmd);

#endif