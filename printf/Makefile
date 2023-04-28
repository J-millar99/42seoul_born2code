# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 22:11:46 by jaehyji           #+#    #+#              #
#    Updated: 2023/04/29 03:09:57 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS_M = ft_printf.c type_cs.c type_di.c type_p.c type_u.c type_x.c utils.c

SRCS_B = ft_printf_bonus.c ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_atoi_bonus.c \
		ft_isdigit_bonus.c ft_memcpy_bonus.c ft_strchr_bonus.c ft_strdup_bonus.c \
		ft_strlen_bonus.c ft_substr_bonus.c	padding_bonus.c set_format_bonus.c \
		utils_bonus.c type_percent_bonus.c type_c_bonus.c type_s_bonus.c \
		type_d_bonus.c type_i_bonus.c type_p_bonus.c type_u_bonus.c type_lx_bonus.c \
		type_ux_bonus.c type_d_flag_bonus.c type_ux_hash_bonus.c type_lx_hash_bonus.c \
		d_nb_zero_bonus.c

OBJS_M = $(addprefix mandatory/srcs/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix bonus/srcs/, ${SRCS_B:.c=.o})
INC_M = -I./mandatory/includes
INC_B = -I./bonus/includes

ifdef FLAG
    OBJS = $(OBJS_B)
	INC = $(INC_B)
else
    OBJS = $(OBJS_M)
	INC = $(INC_M)
endif

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ $(INC)

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
