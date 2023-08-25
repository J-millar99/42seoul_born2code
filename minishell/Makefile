# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 12:05:08 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/25 12:19:26 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = -L ./libft
LIBFTDIR = ./libft
LIBRD = -L ../../../.brew/opt/readline/lib

SRCS = main.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(LIBFT) $(LIBRD) -o $(NAME) $(OBJS) -lreadline -lft

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean
fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
