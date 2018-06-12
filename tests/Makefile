##
## EPITECH PROJECT, 2018
## navy
## File description:
## Makefile for unitests.
##

SRC		=	../src/parse_arg.c

SRC_UT		=	test_parse_arg.c

OBJ		=	$(SRC:.c=.o)	\
			$(SRC_UT:.c=.o)

CPPFLAGS	+=	-I../include

CFLAGS		+=	-Wall -Wextra --coverage

LDFLAGS		+=	-lcriterion -lgcov -L../lib/ -lmy

NAME		=	units

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) $(SRC:.c=.gcda)
		$(RM) $(SRC:.c=.gcno)
		$(RM) $(SRC_UT:.c=.gcda)
		$(RM) $(SRC_UT:.c=.gcno)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
