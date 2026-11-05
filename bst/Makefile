NAME = bst

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g3

SOURCES = bst.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(NAME)
	./$(NAME)

%.o: %.cpp bst.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
