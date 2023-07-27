/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/27 09:44:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define VERTICAL 800
# define HORIZONTAL 1280

# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_file
{
	int		limit_row;
	int		limit_col;
	int		fd;
	char	*filename;
}	t_file;

typedef struct s_map
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

/*	check_utils	*/
void	checking_file(t_file *info);
void	checking_no_data(char *line, t_file *info);
void	checking_map(t_file *info);
void	checking_possible_map(char *line, t_file *info);

/* color_utils	*/
int		ft_atoi_fdf(char **str);
void	ft_atoi_z(t_map *map, char *str);
void	ft_atoi_color(t_map *map, char **str);
int		ft_atoi_hex(char *str);

/*	coordinates_utils	*/
t_map	coordinate(int row, int col, char **arr, t_file *info);
char	**one_coordinate_line(t_file *info);
void	plotting(void *mlx_ptr, void *win_ptr, t_map **map, t_file *info);
void	line_put(void *mlx_ptr, void *win_ptr, t_map map1, t_map map2);
void	locate_mid(t_map *map, t_file *info);
/*	error_utils	*/
void	print_error(char *estr, int code, t_file *info);

/*	key_utils	*/
int		on_key_press(int keycode);
void	input_key(void *win_ptr);

/*	map_utils	*/
t_map	**initial_map(t_file *info);
void	make_map(void *mlx_ptr, t_file *info);

/* rotate_algorithm	*/
void	isometric_projection(t_map **map, t_file *info);
void	rotate_std_x(t_map *map, double theta);
void	rotate_std_y(t_map *map, double theta);
void	rotate_std_z(t_map *map, double theta);

/*	utils	*/
void	initializing_fileinfo(t_file *info, char *filename);
int		is_sep(char c, char sep);
int		word_count(const char *s, char c);
void	free_split(char **array);
void	free_map(t_map **map, t_file *info);
void	initializing_map(t_map *map);
#endif
