# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:54:45 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/09 12:11:59 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
MLXDIR = minilibx_mms_20210621
LIBFT = -L ./libft
MLX = -L ./minilibx_mms_20210621

INCS_M = mandatory/fdf.h
INCS_B = bonus/fdf_bonus.h
INCS_G = get_next_line/get_next_line.h

SRCS_M = fdf.c					\
		check_file.c			\
		error_utils.c			\
		event_hooks.c			\
		get_color.c				\
		get_coordinates.c		\
		initializing_utils.c	\
		map_utils.c				\
		rotate_algorithm.c		\
		screen_utils.c			\
		utils.c

SRCS_B = fdf_bonus.c				\
		check_utils_bonus.c			\
		error_utils_bonus.c			\
		event_hooks_bonus.c			\
		get_color_bonus.c			\
		get_coordinates_bonus.c		\
		initializing_utils_bonus.c	\
		map_utils_bonus.c			\
		move_key_bonus.c			\
		projection_key_bonus.c		\
		rotate_algorithm_bonus.c	\
		rotate_key_bonus.c			\
		screen_utils_bonus.c		\
		size_key_bonus.c			\
		limit_utils_bonus.c			\
		random_color_bonus.c		\
		utils_bonus.c

SRCS_G = get_next_line.c

OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
OBJS_G = $(addprefix get_next_line/, ${SRCS_G:.c=.o})

ifdef B
	OBJS_ALL = $(OBJS_B) $(OBJS_G)
	OBJS_EXCEPT = $(OBJS_M)
	INCS = $(INCS_B) $(INCS_G)
else
	OBJS_ALL = $(OBJS_M) $(OBJS_G)
	OBJS_EXCEPT = $(OBJS_B)
	INCS = $(INCS_M) $(INCS_G)
endif

%.o : %.c $(INCS)
	${GCC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJS_ALL) $(INCS)
	@${RM} $(NAME)
	@${RM} $(OBJS_EXCEPT)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	${GCC} ${FLAGS} ${LIBFT} ${MLX} -o $(NAME) $(OBJS_ALL) -lft -lmlx
	@cd ./$(MLXDIR) ; mv libmlx.dylib ../

all: ${NAME}

bonus:
	@make B=1 $(NAME)

clean:
	${RM} ${OBJS_M} $(OBJS_G) $(OBJS_B)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} libmlx.dylib
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(MLXDIR) && $(MAKE) clean

re: clean all

.PHONY: all clean fclean re bonus