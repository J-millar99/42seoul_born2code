/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:44:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:19:33 by jaehyji          ###   ########.fr       */
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

typedef struct s_cmd
{
	int		hd_fd[2];
	int		mp_fd[2];
	int		file[2];
	char	*infile;
	char	*outfile;
	char	**envp;
	char	*limiter;
}	t_cmd;

/*			HEREDOC			*/
void	here_doc(t_cmd *info, int ac, char **av, char **envp);
void	f_process_hd(pid_t child, t_cmd *info);
void	c_process_hd(t_cmd *info, int *fd);
void	p_process_hd(t_cmd *info, int *fd);

/*			HEREDOC_UTILS			*/
void	check_hd(t_cmd *info, int ac, char **av, char **envp);
void	execute_hd(t_cmd *info);

/*			MULTIPIPE			*/
void	multi_pipe(t_cmd *info, int ac, char **av, char **envp);
void	f_process_mp(t_cmd *info, char *av);
/*			MULTIPIPE_UTILS			*/
void	check_mp(t_cmd *info, int ac, char **av, char **envp);
void	execute_cmdline(t_cmd *info, char *cmdline);
char	*check_path(t_cmd *info, char *cmd);
char	**make_paths(t_cmd *info);
void	check_some(char **paths, char **path, char **cmd_file, t_cmd *info);
/*			UTILS			*/
void	split_free(char **strarr);
void	print_error(char *error_string, int code);
void	init_file_fd(t_cmd *info);
#endif