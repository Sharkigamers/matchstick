##
## EPITECH PROJECT, 2018
## matchstick
## File description:
## Makefile
##

SRC	=	src/matchstick.c	\
		src/stock_map.c	\
		src/disp_map.c	\
		src/free.c	\
		src/fill_map.c	\
		src/gest_error.c	\
		src/dumb_ai.c	\
		src/map.c	\
		src/main.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(SRC) $(LIB) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean re
