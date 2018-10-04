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

NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror
CLANG = clang++
CL = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CLANG) -o $@ -c $< $(FLAGS)

clean:
	$(CL) $(OBJ)

fclean: clean
	$(CL) $(NAME)

re: fclean all