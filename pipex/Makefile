# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 19:12:36 by jaehyji           #+#    #+#              #
#    Updated: 2023/06/12 19:14:13 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
BONUS = heredoc

SRCS = pipex.c	\
		pipex_utils.c

BONUS_SRCS = 

OBJS = ${SRCS:.c=.o}
BONUS_OBJS =${BONUS_SRCS:.c=.o}

LIBFT = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}

${BONUS}: ${BONUS_OBJS}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJS} -o ${BONUS} ${LIBFT}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus