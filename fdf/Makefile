# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:54:45 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/03 12:04:49 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myfdf
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
MLXDIR = minilibx_mms_20210621
LIBFT = -L ./libft
MLX = -L ./minilibx_mms_20210621

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

INCS = fdf.h
BONUS_INCS = fdf_bonus.h

SRCS = fdf.c	\
		map_utils.c	\
		key_utils.c		\
		error_utils.c	\
		check_utils.c	\
		color_utils.c	\
		coordinates_utils.c	\
		rotate_algorithm.c	\
		utils.c		\
		screen_utils.c

BONUS_SRCS = fdf_bonus.c	\
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

GNL = get_next_line.c	\

OBJS = $(addprefix mandatory/, ${SRCS:.c=.o})
HEAD = $(addprefix mandatory/, ${INCS})
BONUS_OBJS = $(addprefix bonus/, ${BONUS_SRCS:.c=.o})
BONUS_HEAD = $(addprefix bonus/, ${BONUS_INCS})
GNL_OBJS = $(addprefix get_next_line/, ${GNL:.c=.o})

ifdef BO
	OBJS_ALL = $(BONUS_OBJS) $(GNL_OBJS)
	OBJS_EXCEPT = $(OBJS)
	HEADER = $(BONUS_HEAD)
else
	OBJS_ALL = $(OBJS) $(GNL_OBJS)
	OBJS_EXCEPT = $(BONUS_OBJS)
	HEADER = $(HEAD)
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
	${RM} ${OBJS} $(GNL_OBJS) $(BONUS_OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} libmlx.dylib
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(MLXDIR) && $(MAKE) clean

re: clean all

.PHONY: all clean fclean re bonus