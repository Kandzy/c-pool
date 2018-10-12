NAME= array
OBJ_DIR=./obj/
SRC_DIR=./
INC_DIR=./
SRC= main.cpp
OBJ=$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC= Array.hpp
CC= clang++
FLAGS= -Wall -Wextra -Werror -std=c++98

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(INC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR)

obj_dir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re