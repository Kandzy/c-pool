NAME= ft_retro
OBJ_DIR=./obj/
SRC_DIR=./src/
INC_DIR=./includes/
SRC= main.cpp SpaceShip.cpp GameLogic.cpp Parametrs.cpp GameScore.cpp Bullet.cpp
OBJ=$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC= SpaceShip.hpp GameLogic.hpp Parametrs.hpp GameScore.hpp Bullet.hpp
CC= clang++
FLAGS= -Wall -Wextra -Werror

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	$(CC) -lncurses $(FLAGS) $(OBJ) -o $(NAME) -I $(INC_DIR)

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
