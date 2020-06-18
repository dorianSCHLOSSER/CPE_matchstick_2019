##
## EPITECH PROJECT, 2019
## makefile
## File description:
## return
##

SRC = 	main.c			\
		src/my_map.c	\
		src/my_player.c	\
		src/my_error.c	\
		src/my_ai.c

OBJ = $(SRC:.c=.o)

NAME = matchstick

FLAGS =  -Llib/my -lmy

all:
	make -C lib/my build
	gcc -g -o $(NAME) $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)
		rm -f ./lib/my/*.o
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		rm -f ./lib/*.a
		rm -f ./lib/my/*.a

re: fclean all