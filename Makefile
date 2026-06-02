##
## EPITECH PROJECT, 2026
## Calculator
## File description:
## Makefile
##

CC			=	clang
INCLUDE		=	-I./include/
CFLAGS		=	-Wall -Wextra $(INCLUDE) -lm

SRCF		=	src/
SRC			=	$(SRCF)checks.c		\
				$(SRCF)ast.c		\
				$(SRCF)ast_utils.c		\
				$(SRCF)execute.c		\
				$(SRCF)operation.c		\

OBJ			=	$(SRC:.c=.o)

NAME		=	./calculator

MAIN		=	$(SRCF)main.c		\

all:		$(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MAIN) $(CFLAGS) -o $(NAME)

%o:			%.c
	$(CC) $(LIB) -o $< -c $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all
