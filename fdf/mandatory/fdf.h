/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/03 22:51:36 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define VERTICAL 800
# define HORIZONTAL 1200

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
	double	max_height;
	double	min_height;
	double	width;
	double	height;
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

typedef struct s_mlx
{
	void	*mptr;
	void	*wptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
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
void	draw(t_mlx *mlx, t_map **map, t_file *info);
void	draw_line(t_mlx *mlx, t_map p, t_map q);

/*	error_utils	*/
void	print_error(char *estr, int code, t_file *info);

/*	key_utils	*/
void	input_key(t_mlx *mlx);
int		on_key_press(int keycode, t_mlx *mlx);

/*	map_utils	*/
t_map	**initial_map(t_file *info);
void	make_map(t_mlx *mlx, t_file *info);
void	plotting(t_mlx *mlx, t_map **map, t_file *info);

/* rotate_algorithm	*/
void	isometric_projection(t_map **map, t_file *info);
void	rotate_std_y(t_map *map, double theta);
void	rotate_std_z(t_map *map, double theta);

/*	initializing_utils	*/
void	initializing_fileinfo(t_file *info, char *filename);
void	initializing_coordinates_data(t_map *map);

/*	utils	*/
int		is_sep(char c, char sep);
int		word_count(const char *s, char c);
void	free_split(char **array);
void	free_map(t_map **map, t_file *info);
void	get_height(t_map **map, t_file *info);

/*	screen_utils	*/
void	setting_window(t_mlx *mlx, t_file *info);
void	setting_img_data(t_mlx *mlx, t_file *info);
void	extend_screen(t_map **map, t_file *info, int mtp);
void	adjusting_screen(t_map **map, t_file *info);


#endif
