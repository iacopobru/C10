COMPILER = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_display_file.c
NAME = ft_display_file
OBj = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBj)
	gcc $(FLAGS) $(OBj) -o $(NAME)

clean:
	rm -f $(OBj)

fclean: clean
	rm -f $(NAME)