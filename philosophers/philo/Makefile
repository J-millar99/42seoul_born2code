# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millar <millar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/11/09 16:57:20 by millar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS = philo.h

SRCS = philo.c	\
	check_input_utils.c \
	check_input.c	\
	clean_up.c	\
	ft_modstr.c	\
	ft_split.c	\
	eating.c	\
	set_enviornment.c	\
	simulate_utils.c	\
	simulate.c	\
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