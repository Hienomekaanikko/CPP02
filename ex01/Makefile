CC = c++
FLAGS = -Wall -Werror -Wextra
SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = a.out
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
