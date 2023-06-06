# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:52:43 by jaehyji           #+#    #+#              #
#    Updated: 2023/06/05 14:03:26 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
BONUS = checker

SRCS_M = push_swap.c

SRCS_U =	stack_utils.c	\
		sort_utils.c	\
		lst_utils1.c	\
		lst_utils2.c	\
		push_utils.c	\
		swap_utils.c	\
		rotate_utils.c	\
		rotate_reverse_utils.c	\
		rotate_case_atob.c	\
		rotate_case_btoa.c	\
		rotate_push.c	\
		find_value_utils.c	\
		error_checker.c	\
		error_checker_utils.c	\
		check_rotate_type.c

BONUS_SRCS = push_swap_checker/checker.c	\
			push_swap_checker/push_type.c	\
			push_swap_checker/swap_type.c	\
			push_swap_checker/rotate_type.c	\
			get_next_line/srcs/get_next_line.c	\
			get_next_line/srcs/get_next_line_utils.c

OBJS_M = ${SRCS_M:.c=.o}
OBJS_U = ${SRCS_U:.c=.o}
BONUS_OBJS =${BONUS_SRCS:.c=.o}

LIBFT = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS_M} ${OBJS_U}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJS_M} ${OBJS_U} -o ${NAME} ${LIBFT}

${BONUS}: ${OBJS_U} ${BONUS_OBJS}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJS} ${OBJS_U} -o ${BONUS} ${LIBFT}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJS_M} ${OBJS_U} ${BONUS_OBJS} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus