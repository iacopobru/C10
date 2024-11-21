COMPILER = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_cat.c
NAME = ft_cat
OBj = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBj)
	gcc $(FLAGS) $(OBj) -o $(NAME)

clean:
	rm -f $(OBj)

fclean: clean
	rm -f $(NAME)
