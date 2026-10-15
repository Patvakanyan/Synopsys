NAME = vec

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g3

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_NAME = vector_tests

.PHONY: all clean fclean re test

all: $(NAME)

test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): tests.cpp vector.hpp vector.ipp
	$(CXX) $(CXXFLAGS) tests.cpp -o $(TEST_NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp vector.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

