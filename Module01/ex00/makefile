# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
NAME = zombie

# Source files
SRCS = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

# Object files (automatically generated)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything (objects + executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets (not files)
.PHONY: all clean fclean re