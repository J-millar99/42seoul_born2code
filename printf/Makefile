# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 22:11:46 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/08 08:23:02 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf
AR = ar
CRS = crs

INCS_M = mandatory/includes/ft_printf.h

SRCS_M = ft_printf.c type_cs.c type_di.c type_p.c type_u.c type_x.c utils.c

INCS_B = bonus/includes/ft_printf_bonus.h

SRCS_B = ft_printf_bonus.c ft_putchar_fd_bonus.c	\
		ft_putstr_fd_bonus.c ft_atoi_bonus.c	\
		ft_isdigit_bonus.c ft_memcpy_bonus.c	\
		ft_strchr_bonus.c ft_strdup_bonus.c	\
		ft_strlen_bonus.c ft_substr_bonus.c	\
		padding_bonus.c set_format_bonus.c	\
		utils_bonus.c type_percent_bonus.c	\
		type_c_bonus.c type_s_bonus.c	\
		type_d_bonus.c type_i_bonus.c	\
		type_p_bonus.c type_u_bonus.c	\
		type_lx_bonus.c	type_ux_bonus.c	\
		type_d_flag_bonus.c type_ux_hash_bonus.c	\
		type_lx_hash_bonus.c d_nb_zero_bonus.c

OBJS_M = ${addprefix mandatory/srcs/, $(SRCS_M:.c=.o)}
OBJS_B = ${addprefix bonus/srcs/, $(SRCS_B:.c=.o)}

ifdef B
    OBJS = $(OBJS_B)
	INCS = $(INCS_B)
else
    OBJS = $(OBJS_M)
	INCS = $(INCS_M)
endif

%.o : %.c $(INCS)
	$(GCC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(CRS) $(NAME) $(OBJS)
	
all : $(NAME)

clean :
	@$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	@$(RM) $(NAME)

re :
	make fclean
	make all

bonus :
	@make B=1 all

.PHONY : all clean fclean re bonus
