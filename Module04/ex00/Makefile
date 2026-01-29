CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Dog.cpp Animal.cpp Cat.cpp wrong/WrongCat.cpp wrong/WrongAnimal.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re