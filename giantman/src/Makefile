##
## EPITECH PROJECT, 2022
## giantman
## File description:
## decompress given file
##

SRC	=	$(wildcard src/*.c)	giantman.c

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
