# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:52:43 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/08 08:37:00 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
GCC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFTDIR = libft
LIBFT = -L ./libft -lft

INCS_P = mandatory/push_swap.h

INCS_G = get_next_line/get_next_line.h

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

SRCS_B = checker_bonus.c	\
		command_bonus.c		\

SRCS_G = get_next_line.c	\
	get_next_line_utils.c

OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
OBJS_U = $(addprefix mandatory/, ${SRCS_U:.c=.o})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
OBJS_G = $(addprefix get_next_line/, ${SRCS_G:.c=.o})
INCS = $(INCS_P) $(INCS_G)

%.o : %.c
	$(GCC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS_M) $(OBJS_U) $(OBJS_G) $(INCS)
	make -C $(LIBFTDIR)
	$(GCC) $(FLAGS) $(OBJS_M) $(OBJS_U) $(OBJS_G) -o $(NAME) $(LIBFT)

$(BONUS): $(OBJS_U) $(OBJS_B) $(OBJS_G) $(INCS)
	make -C $(LIBFTDIR)
	$(GCC) $(FLAGS) $(OBJS_B) $(OBJS_U) $(OBJS_G) -o $(BONUS) $(LIBFT)

all: $(NAME)

bonus: $(BONUS) 

clean:
	$(RM) $(OBJS_M) $(OBJS_U) $(OBJS_B) $(OBJS_G)
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus