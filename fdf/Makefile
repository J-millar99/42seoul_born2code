# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:54:45 by jaehyji           #+#    #+#              #
#    Updated: 2023/07/25 16:09:22 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myfdf
CC = gcc
RM = rm -f
# FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
MLXDIR = minilibx_mms_20210621
LIBFT = -L ./libft
MLX = -L ./minilibx_mms_20210621

.c.o:
	${CC} $(FLAGS) -c $< -o ${<:.c=.o}

SRCS = fdf.c	\
		image_utils.c	\
		key_utils.c		\
		error_utils.c	\
		check_utils.c

GNL = get_next_line.c	\

OBJS = $(addprefix mandatory/, ${SRCS:.c=.o})
GNL_OBJS = $(addprefix get_next_line/, ${GNL:.c=.o})

$(NAME): $(OBJS) $(GNL_OBJS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	${CC} ${LIBFT} ${MLX} -o $@ $^ -lft -lmlx
	@cd ./$(MLXDIR) ; mv libmlx.dylib ../

all: ${NAME}

clean:
	${RM} ${OBJS} $(GNL_OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} libmlx.dylib
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(MLXDIR) && $(MAKE) clean

re: clean all

.PHONY: all clean fclean re bonus