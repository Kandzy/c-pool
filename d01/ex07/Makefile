# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:50:16 by dkliukin          #+#    #+#              #
#    Updated: 2018/10/01 10:50:19 by dkliukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
SRC = main.cpp Sed.class.cpp
OBJ = $(SRC:.cpp=.o)
INC = 
FLAGS = -Wall -Wextra -Werror
CLANG = clang++
CL = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CLANG) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	$(CLANG) $(FLAGS) -o $@ -c $< 

clean:
	$(CL) $(OBJ)

fclean: clean
	$(CL) $(NAME)

re: fclean all