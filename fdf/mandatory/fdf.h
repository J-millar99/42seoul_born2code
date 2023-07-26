/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/26 14:54:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_info
{
	int	fd;
}	t_info;

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
	void	*next;
}	t_map;

/*	map_check	*/
void	check_file(char *filename, t_info *info);
void	check_no_data(char *line, t_info *info);
void	check_map(char *av, t_info *info);
void	check_possible_map(char *line, t_info *info);
int		check_num(char **arr);

/*	key_utils	*/
void	input_key(void *mlx_ptr, void *win_ptr);
int		on_key_press(int keycode, void *param);

/*	image_utils	*/
void	set_image(void *mlx_ptr, void *win_ptr, t_info *info);

/*	error_utils	*/
void	print_error(char *estr, int code, t_info *info);
void	free_arr(char **arr, t_info *info);

#endif