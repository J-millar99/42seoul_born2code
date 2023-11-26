# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millar <millar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/11/26 22:03:35 by millar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS = philo_bonus.h

SRCS = check_input_bonus.c		\
		clean_up_bonus.c		\
		error_bonus.c			\
		ft_string_bonus.c		\
		ft_split_bonus.c		\
		philo_bonus.c			\
		routine_bonus.c			\
		semaphore_bonus.c		\
		set_enviornment_bonus.c	\
		utils_bonus.c			\
		ft_itoa_bonus.c			\

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