CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_isascii.c ft_memcpy.c\
    ft_strlcat.c ft_strrchr.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c\
    ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memchr.c\
    ft_strchr.c ft_strncmp.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c

OBJS = $(SRCS:.c=.o)
HEADER = libft.h
all: $(NAME)
$(NAME): $(OBJS)
	ar src $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re