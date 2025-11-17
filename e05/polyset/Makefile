# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 19:46:34 by anemet            #+#    #+#              #
#    Updated: 2025/11/17 15:25:19 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -g -fPIE

# The name of the executable
NAME = polyset

# Source files
SRCS = array_bag.cpp  searchable_array_bag.cpp  set.cpp  \
       main.cpp       searchable_tree_bag.cpp  tree_bag.cpp


# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Rule to link the object files and create the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile a .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files
clean:
	rm -f $(OBJS)

# Fclean target to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Re target to rebuild everything
re: fclean all


# debug
debug:
	@echo CXX = $(CXX)
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo NAME = $(NAME)
	@echo SRCS = $(SRCS)
	@echo OBJS = $(OBJS)
	@echo
	@echo --------------
	@echo
	@$(MAKE) all MAKEFLAGS="--trace"


.PHONY: all clean fclean re debug
