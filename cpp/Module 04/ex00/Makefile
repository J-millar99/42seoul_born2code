NAME = a.out
CPP = c++
CPP_FLAGES = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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