/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:44:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 13:16:40 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_hd
{
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
	char	**envp;
	char	*limiter;
}	t_hd;

typedef struct s_mp
{
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	char	**envp;
}	t_mp;

/*			HEREDOC			*/
void	here_doc(int ac, char **av, char **envp);
void	f_process_fd(pid_t child, t_hd *info, int *fd);
void	c_process_hd(t_hd *info, int *fd);
void	p_process_hd(t_hd *info, int *fd);
int		execute_hd(t_hd *info);
void	execute_cmdline_hd(t_hd *info, char **cmd, char f);

/*			HEREDOC_UTILS			*/
void	check_hd(t_hd *info, int ac, char **av, char **envp);
void	check_space_command_hd(char **av);
void	parsing_cmdline_hd(t_hd *info, char **av, char **envp);
void	malloc_free_hd(t_hd *info);
void	print_error_hd(char *error_string, t_hd *info, int code);
void	check_file_hd(t_hd *info);
void	check_command_hd(t_hd *info);
char	*check_path_hd(t_hd *info, char *cmd);
char	**make_paths_hd(t_hd *info);
void	check_some_hd(char **paths, char **path, char **cmd_file, t_hd *info);

/*			MULTIPIPE			*/

/*			MULTIPIPE_UTILS			*/


/*			UTILS			*/
void	split_free(char **strarr);
void	print_error(char *error_string);
#endif