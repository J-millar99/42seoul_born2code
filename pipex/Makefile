# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 19:12:36 by jaehyji           #+#    #+#              #
#    Updated: 2023/06/21 14:58:21 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft

SRCS = pipex.c	\
		pipex_utils.c	\
		process.c	\
		error_utils.c	\
		check_file.c	\
		check_cmd.c

BONUS_SRCS = pipex_bonus.c	\
			here_doc_bonus.c	\
			here_doc_utils_bonus.c	\
			utils_bonus.c

GNL = get_next_line.c	\
		get_next_line_utils.c
			

OBJS = $(addprefix mandatory/, ${SRCS:.c=.o})
BONUS_OBJS = $(addprefix bonus/, ${BONUS_SRCS:.c=.o})
GNL_OBJS = $(addprefix bonus/get_next_line, ${GNL:.c=.o})

LIBFT = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}

${BONUS}: ${BONUS_OBJS} ${GNL_OBJS}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJS} ${GNL_OBJS} -o ${BONUS} ${LIBFT}

all: ${NAME}

bonus: ${BONUS} 

clean:
	${RM} ${OBJS} ${BONUS_OBJS} ${GNL_OBJS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus