# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 17:06:59 by jaehyji           #+#    #+#              #
#    Updated: 2023/04/04 17:06:59 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Wextra -Werror


SRCS_M = ft_printf.c p_char.c p_str.c p_pointer.c p_decimal.c p_unsigned.c \
		p_hex.c

OBJS_M = $(SRCS_M:.c=.o)
#OBJS_B = $(SRCS_B:.c=.o)

ifdef FLAG
    OBJS = $(OBJS_M) $(OBJS_B)
else
    OBJS = $(OBJS_M)
endif

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I./

$(NAME) : $(OBJS)
	ar crs $@ $^
	
all : $(NAME)

clean :
	rm -rf $(OBJS_M) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

bonus :
	@make FLAG=1 all

.PHONY : all clean fclean re bonus
