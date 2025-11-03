# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 19:46:34 by anemet            #+#    #+#              #
#    Updated: 2025/11/01 14:39:20 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fPIE

# The name of the executable
NAME = interface

# Source files
SRCS = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  MateriaSource.cpp  main.cpp

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

.PHONY: all clean fclean re
