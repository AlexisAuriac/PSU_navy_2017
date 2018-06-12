##
## EPITECH PROJECT, 2017
## navy
## File description:
## Makefile for navy.
##

SRC		=	src/main.c	\
			src/parse_arg.c	\
			src/connect.c	\
			src/signal.c	\
			src/navy.c	\
			src/map.c	\
			src/map_2.c	\
			src/game.c	\
			src/error_map.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-Llib/ -lmy

NAME		=	navy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
		make -C tests/

clean	:
		$(RM) $(OBJ)
		make clean -C tests

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C tests

re	:	fclean	all

.PHONY	:	all tests_run clean fclean re
