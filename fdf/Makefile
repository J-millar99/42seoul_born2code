# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:54:45 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/03 22:48:53 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myfdf
GCC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
MLXDIR = minilibx_mms_20210621
LIBFT = -L ./libft
MLX = -L ./minilibx_mms_20210621

.c.o:
	${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

INCS_M = fdf.h
INCS_B = fdf_bonus.h

SRCS_M = fdf.c	\
		map_utils.c	\
		event_hooks.c	\
		error_utils.c	\
		check_utils.c	\
		color_utils.c	\
		coordinates_utils.c	\
		rotate_algorithm.c	\
		utils.c		\
		screen_utils.c	\
		initializing_utils.c

SRCS_B = fdf_bonus.c	\
		map_utils_bonus.c	\
		key_utils_bonus.c		\
		error_utils_bonus.c	\
		check_utils_bonus.c	\
		color_utils_bonus.c	\
		coordinates_utils_bonus.c	\
		rotate_algorithm_bonus.c	\
		utils_bonus.c		\
		size_utils_bonus.c	\
		rotate_utils_bonus.c	\
		projection_utils_bonus.c	\
		initializing_utils_bonus.c

SRCS_G = get_next_line.c	\

OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
INCS_M = $(addprefix mandatory/, ${INCS_M})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
INCS_B = $(addprefix bonus/, ${INCS_B})
OBJS_G = $(addprefix get_next_line/, ${SRCS_G:.c=.o})

ifdef B=1
	OBJS_ALL = $(OBJS_B) $(OBJS_G)
	OBJS_EXCEPT = $(OBJS)
	HEADER = $(INCS_B)
else
	OBJS_ALL = $(OBJS) $(OBJS_G)
	OBJS_EXCEPT = $(OBJS_B)
	HEADER = $(INCS_M)
endif

$(NAME): $(OBJS_ALL) $(HAEDER)
	${RM} $(NAME)
	${RM} $(OBJS_EXCEPT)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	${CC} ${FLAGS} ${LIBFT} ${MLX} -o $(NAME) $(OBJS_ALL) -lft -lmlx
	@cd ./$(MLXDIR) ; mv libmlx.dylib ../

all: ${NAME}

bonus:
	@make BO=1 $(NAME)

clean:
	${RM} ${OBJS} $(OBJS_G) $(OBJS_B)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} libmlx.dylib
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(MLXDIR) && $(MAKE) clean

re: clean all

.PHONY: all clean fclean re bonus