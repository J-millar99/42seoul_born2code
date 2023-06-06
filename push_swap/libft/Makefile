# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 02:01:07 by jaehyji           #+#    #+#              #
#    Updated: 2023/06/05 13:45:54 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS_M =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c	\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c	\
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c	\
			ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c	\
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c	\
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c	\

SRCS_B =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c	\
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c	\
			ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c	\

OBJS_M = $(addprefix srcs/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix srcs/, ${SRCS_B:.c=.o})
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
	make FLAG=1 all

bonus :
	@make FLAG=1 all

.PHONY : all clean fclean re bonus
