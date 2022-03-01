##
## EPITECH PROJECT, 2021
## antman
## File description:
## simple_description
##

ANT	=	antman

GIANT	=	giantman

NAME	=	yes

all:	$(NAME)

$(NAME):
	make -C $(ANT)
	make -C $(GIANT)
clean:
	make clean -C $(ANT)
	make clean -C $(GIANT)

fclean:
	make fclean -C $(ANT)
	make fclean -C $(GIANT)

re:	fclean	all

unit_tests:
	make unit_tests -C $(ANT)
	make unit_tests -C $(GIANT)

tests_run:
	make tests_run -C $(ANT)
	make tests_run -C $(GIANT)
