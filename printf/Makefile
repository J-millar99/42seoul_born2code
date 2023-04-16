# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 22:11:46 by jaehyji           #+#    #+#              #
#    Updated: 2023/04/16 22:11:46 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Wextra -Werror


SRCS_M = ft_printf.c p_char.c p_str.c p_pointer.c p_decimal.c p_unsigned.c \
		p_hex.c
SRCS_B = type_c_bonus.c type_d_bonus.c type_i_bonus.c type_p_bonus.c \
		type_s_bonus.c type_x_bonus.c type_percent_bonus.c  utils_bonus.c \
		set_format_bonus.c padding_bonus.c ft_atoi.c ft_isdigit.c ft_strlen.c \
		ft_substr.c ft_strchr.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_strdup.c ft_memcpy.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef FLAG
    OBJS = $(OBJS_M) $(OBJS_B)
else
    OBJS = $(OBJS_M)
endif

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

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
