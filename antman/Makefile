##
## EPITECH PROJECT, 2022
## antman
## File description:
## compress a file to a certain degree
##

SRC	=	$(wildcard src/*.c)	antman.c

SRCD	=	$(wildcard src/*.c)

TESTS	=	$(wildcard tests/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

NAME	=	antman

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

unit_tests:	fclean	antman
	gcc -o unit_tests $(SRCD) $(TESTS) $(CFLAGS) --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests
