# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millar <millar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/11/23 20:04:04 by millar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

INCS = philo.h

SRCS = philo.c	\
	check_input.c	\
	clean_up.c	\
	ft_modstr.c	\
	ft_split.c	\
	behavior.c	\
	set_enviornment.c	\
	simulate.c	\
	utils.c	\

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCS)
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME)
	@make clean

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus