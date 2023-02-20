
CFLAGS=-Werror -Wextra -Wall 
NAME=minishell

SRC= main.c

OBJ= ${SRC:%.c=%.o}

$(NAME): ${OBJ}
	@make -C ./libft/
	gcc $(OBJ) -o $(NAME) $(CFLAGS) ./libft/libft.a -lreadline

all:	${NAME}

clean:
	@make -C ./libft/
	rm -f ${OBJ}

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all