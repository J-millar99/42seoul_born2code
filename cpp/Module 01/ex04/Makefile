NAME = sed
CPP = c++
CPP_FLAGES = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp replaceFileName.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CPP) $(CPP_FLAGES) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPP_FLAGES) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)