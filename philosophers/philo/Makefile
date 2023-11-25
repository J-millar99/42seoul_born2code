# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millar <millar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/11/25 19:55:54 by millar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS = philo.h

SRCS = philo.c	\
	check_status.c	\
	check_input.c	\
	clean_up.c	\
	ft_string.c	\
	ft_split.c	\
	routine.c	\
	set_enviornment.c	\
	utils.c	\

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus