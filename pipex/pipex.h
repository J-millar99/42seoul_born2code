/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 20:24:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
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

/*			pipex			*/

/*			error			*/
void	print_error(char *error_strting);
void	malloc_error(t_cmdline *info);

/*			utils			*/
void	malloc_free(t_cmdline *info);
void	parsing_cmd(t_cmdline *info, char **av, char **envp);
void	check_command(t_cmdline *info);
void	check_file(t_cmdline *info);

#endif