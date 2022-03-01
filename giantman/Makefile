##
## EPITECH PROJECT, 2022
## giantman
## File description:
## decompress given file
##

SRC	=	$(wildcard src/*.c)	giantman.c

SRCD	=	$(wildcard src/*.c)

TESTS	=	$(wildcard tests/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

NAME	=	giantman

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

unit_tests:	fclean	giantman
	gcc -o unit_tests $(SRCD) $(TESTS) $(CFLAGS) --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests
