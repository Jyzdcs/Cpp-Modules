# Compile and flags
CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Exec name
NAME = horde

# Srcs files
SRCS = main.cpp zombieHorde.cpp Zombie.cpp

# Obj
OBJS = $(SRCS:.cpp=.o)

#default target
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

# Compile sources files to objects files
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re