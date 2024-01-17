NAME = a.out
CPP = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# CXXFLAGS += -Wshadow
# CXXFLAGS += -Wno-shadow

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp %.hpp
	$(CPP) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re