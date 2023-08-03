/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 14:17:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
/*	setting_value	*/
# define VER 1000
# define HOR 1200
# define W_MAX -1
# define W_MIN  1
/*	key_setting	*/
# define PJ_A 18
# define PJ_B 19
# define PJ_C 20
# define PLUS 24
# define MINUS 27
# define X 7
# define Y 16
# define Z 6
# define ERASE 29
# define ESC 53

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
	double	std_x;
	double	std_y;
	double	std_z;
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

typedef struct s_mlx
{
	void	*mptr;
	void	*wptr;
	t_file	*info;
	t_map	**map;
	int		w_max;
	int		w_min;
	int		on_img;
}	t_mlx;

/*	check_utils	*/
void	checking_file(t_file *info);
void	checking_no_data(char *line, t_file *info);
void	checking_map_data(t_file *info);
void	checking_possible_map(char *line, t_file *info);

/* color_utils	*/
int		ft_atoi_fdf(char **str);
void	ft_atoi_z(t_map *map, char *str);
void	ft_atoi_color(t_map *map, char **str);
int		ft_atoi_hex(char *str);

/*	coordinates_utils	*/
t_map	coordinate(int row, int col, char **arr, t_file *info);
char	**one_coordinate_line(t_file *info);
void	locate_mid(t_map **map, t_file *info);
void	locate_zero(t_mlx *mlx);
void	initializing_coordinates(t_map **map, t_file *info);

/*	error_utils	*/
void	print_error(char *estr, int code, t_file *info);

/*	key_utils	*/
void	input_key(t_mlx *mlx);
int		on_key_press(int keycode, t_mlx *mlx);

/*	map_utils	*/
t_map	**initial_map(t_file *info);
void	make_map(t_mlx *mlx, t_file *info);
void	plotting(t_mlx *mlx, t_map **map, t_file *info);
void	line_put(t_mlx *mlx, t_map map1, t_map map2);

/* rotate_algorithm	*/
void	rotate_std_x(t_map *map, double theta);
void	rotate_std_y(t_map *map, double theta);
void	rotate_std_z(t_map *map, double theta);

/*	utils	*/
int		is_sep(char c, char sep);
int		word_count(const char *s, char c);
void	free_split(char **array);
void	free_map(t_map **map, t_file *info);
int		click_close(t_mlx *mlx);

/*	size_utils	*/
void	extend_screen(t_mlx *mlx);
void	contract_screen(t_mlx *mlx);
void	key_size(t_mlx *mlx, int keycode);

/*	rotate_utils	*/
void	key_rotate(t_mlx *mlx, int keycode);
void	rotate_x(t_mlx *mlx);
void	rotate_y(t_mlx *mlx);
void	rotate_z(t_mlx *mlx);

/*	initializing_utils	*/
void	initializing_coordinates_data(t_map *map);
void	setting_mlx(t_mlx *mlx, t_map **map, t_file *info);
void	initializing_fileinfo(t_file *info, char *filename);

/*	projection_utils	*/
void	key_projection(t_mlx *mlx, int keycode);
void	isometric_projection(t_map **map, t_file *info);
void	orthographic_projection(t_map **map, t_file *info);
void	oblique_projection(t_map **map, t_file *info);

#endif
