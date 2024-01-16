NAME = a.out
CPP = c++
CPP_FLAGES = -Wall -Wextra -Werror -std=c++98
CPP_FLAGES += -Wshadow
# CPP_FLAGES += -Wno-shadow

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp %.hpp
	$(CPP) $(CPP_FLAGES) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPP_FLAGES) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)