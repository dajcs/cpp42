# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 12:50:39 by anemet            #+#    #+#              #
#    Updated: 2025/10/24 12:41:05 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The compiler to use
CXX = c++

# Flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# name
NAME = megaphone

# source files
SRCS = Megaphone.cpp

# obj files generated from the source files
OBJS = $(SRCS:.cpp=.o)

# the default rule, when just `make` is typed
all: $(NAME)

# rule to build the final executable $(NAME)
# It depends on the object files $(OBJS)
# the command links the object files together
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# target: dependencies
# <tab>	command(s)

# Rule to compile shource files (.cpp) into object files (.o)

# %.o: %.cpp  ==  to create any *.o find the corresponding *.cpp
#                 so when Megaphone.o needs to be built sees that
#				  Megaphone.cpp exists and uses this rule
# The -c flag tells the compiler to compile the source code 
# into an intermediate "object file" (.o) but do not link it yet
# $< : the first dependency (the .cpp file). In our case Megaphone.cpp
# $@ : the target of the rule (the .o file). In our case Megaphone.o

# c++ -Wall -Wextra -Werror -std=c++98 -c Megaphone.cpp -o Megaphone.o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to remove generated files (object files and the executable)
clean:
	rm -f $(OBSJ)

# Rule to remove everything "clean" does, plus the final executable
fclean: clean
	rm -f $(NAME)

# Re target to rebuild everything
re: fclean all

# Phony
.PHONY: all clean fclean re