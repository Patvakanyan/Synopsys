CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS = string2.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(OBJS)

%.o: %.cpp string2.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean

re: fclean all
