# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/11/24 13:50:47 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS = philo.h

SRCS = philo.c	\
	check_status.c	\
	check_input.c	\
	clean_up.c	\
	ft_modstr.c	\
	ft_split.c	\
	routine.c	\
	set_enviornment.c	\
	utils.c	\

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCS)
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus