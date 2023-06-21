/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:44:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 17:44:06 by jaehyji          ###   ########.fr       */
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

}	t_hd;

typedef struct s_mp
{
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	char	**envp;
}	t_mp;

void	check_av(t_mp *info, int ac, char **av, int *file);
void	setting_file(t_mp *info, int ac, char **av, int *file);

/*			HEREDOC			*/
void	here_doc(int ac, char **av, char **envp);

/*			HEREDOC_UTILS			*/
void	malloc_free_hd(t_hd *info);
void	print_error_hd(char *error_strting, t_hd *info, int code);
void	check_hd(t_hd *info, int ac, char **av, char **envp);
void	check_command_space_hd(char **av);
void	parsing_cmdline_hd(t_hd *info, char **av, char **envp);
void	check_command_hd(t_hd *info);
char	*check_path_hd(t_hd *info, char *cmd);
char	**make_paths_hd(t_hd *info);
void	check_some_hd(char **paths, char **path, char **cmd_file, t_hd *info);
void	check_file_hd(t_hd *info);

/*			MULTIPIPE		*/


/*			UTILS			*/
void	split_free(char **strarr);

#endif