
CFLAGS=-Werror -Wextra -Wall -g -fsanitize=address
NAME=minishell

SRC= main.c\
	utils.c\

OBJ= ${SRC:%.c=%.o}

$(NAME): ${OBJ}
	@make -C ./libft/
	gcc $(OBJ) -o $(NAME) $(CFLAGS) ./libft/libft.a -lreadline

all:	${NAME}

clean:
	@make -C ./libft/
	rm -f ${OBJ}

fclean: clean
	./libft/ make fclean
	/bin/rm -f $(NAME)

re: fclean all