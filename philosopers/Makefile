# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/18 17:10:43 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS = philo_bonus

GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS_M = philo/philo.h
INCS_B = philo_bonus/philo_bonus.h

SRCS_M = philo.c	\
		ft_modstr.c	\
		ft_split.c	\
		check_input.c	\
		clean_up.c		\

SRCS_B = philo_bonus.c

OBJS_M = $(addprefix philo/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix philo_bonus/, ${SRCS_B:.c=.o})

ifdef B
	OBJS_ALL = $(OBJS_B)
	OBJS_EXCEPT = $(OBJS_M)
	INCS = $(INCS_B)
else
	OBJS_ALL = $(OBJS_M)
	OBJS_EXCEPT = $(OBJS_B)
	INCS = $(INCS_M)
endif

%.o: %.c $(INCS)
	${GCC} $(FLAGS) -c $< -o $@

${NAME}: $(OBJS_ALL)
	${GCC} ${FLAGS} ${OBJS_ALL} -o ${NAME}

all : ${NAME}

bonus :
	@make B=1 $(NAME)

clean:
	@${RM} ${OBJS_M} ${OBJS_B}

fclean: clean
	@${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus