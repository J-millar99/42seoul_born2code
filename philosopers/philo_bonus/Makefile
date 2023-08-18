# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:58:14 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/18 17:23:12 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

GCC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

INCS = philo_bonus.h

SRCS = philo_bonus.c	\


OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCS)
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

bonus :
	@make B=1 $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus