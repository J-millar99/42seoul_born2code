# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 19:12:36 by jaehyji           #+#    #+#              #
#    Updated: 2023/08/09 16:49:16 by jaehyji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
GCC = gcc
RM = rm -rf
FLAGS =
LIBFTDIR = libft
LIBFT = -L ./libft -lft

INCS_M = mandatory/pipex.h
INCS_B = bonus/pipex_bonus.h
INCS_G = get_next_line/get_next_line.h

SRCS_M = pipex.c	\
		pipex_utils.c	\
		process.c	\
		error_utils.c	\
		check_file.c	\
		check_cmd.c

SRCS_B = pipex_bonus.c	\
			here_doc_bonus.c	\
			here_doc_utils_bonus.c	\
			multi_pipe_bonus.c	\
			multi_pipe_utils_bonus.c	\
			utils_bonus.c	\
			error_utils_bonus.c

SRCS_G = get_next_line.c	\
		get_next_line_utils.c

OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
OBJS_G = $(addprefix get_next_line/, ${SRCS_G:.c=.o})

ifdef B
	OBJS_ALL = $(OBJS_B) $(OBJS_G)
	OBJS_EXCEPT = $(OBJS_M)
	INCS = $(INCS_B) $(INCS_G)
else
	OBJS_ALL = $(OBJS_M)
	OBJS_EXCEPT = $(OBJS_B) $(OBJS_G)
	INCS = $(INCS_M)
endif

%.o: %.c $(INCS)
	${GCC} $(FLAGS) -c $< -o $@

${NAME}: $(OBJS_ALL) $(INCS)
	@${RM} $(NAME)
	@${RM} $(OBJS_EXCEPT)
	@make -C $(LIBFTDIR)
	${GCC} ${FLAGS} ${OBJS_ALL} -o ${NAME} ${LIBFT}

all: ${NAME}

bonus :
	@make B=1 $(NAME)

clean:
	@${RM} ${OBJS_M} ${OBJS_B} ${OBJS_G}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus