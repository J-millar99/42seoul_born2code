# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:52:43 by jaehyji           #+#    #+#              #
#    Updated: 2023/06/05 12:50:12 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
PRINTFDIR = printf/
GNLDIR = get_next_line/
BONUS = checker

SRCS = push_swap.c	\
		stack_utils.c	\
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
		check_rotate_type.c	\
		ft_split.c	\
		ft_strjoin.c

BONUS_SRCS = checker/checker.c	\
			checker/push_type.c	\
			checker_swap_type.c	\
			checker/rotate_type.c	\
			get_next_line/srcs/get_next_line.c	\
			get_next_line/srcs/get_next_line_utils.c

OBJC = ${SRCS:.c=.o}
BONUS_OBJC =${BONUS_SRCS:.c=.o}

PRINTF = -L ./printf -printf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJC}
	make -C $(PRINTFDIR)
	${CC} ${FLAGS} ${OBJC} -o ${NAME} ${LIBFT} ${PRINTF}

${BONUS}: ${OBJC} ${BONUS_OBJC}
	make -C $(PRINTFDIR)
	${CC} ${FLAGS} ${BONUS_OBJC} ${OBJC} -o ${BONUS} ${LIBFT} ${PRINTF}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJC} ${BONUS_OBJC}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(PRINTFDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(PRINTFDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus