
CFLAGS=-Werror -Wextra -Wall #-g -fsanitize=address
NAME=minishell

SRC= main.c\
	utils.c\
	check_unexpected_token.c\
	signal.c\

OBJ= ${SRC:%.c=%.o}

LIBR = -lreadline -L /Users/$(USER)/.brew/Cellar/readline/8.2.1/lib
LIBPATH = ~/.brew/Cellar/readline/8.2.1/lib

$(NAME): ${OBJ}
	@make -C ./libft/
	gcc $(OBJ) $(CFLAGS) ./libft/libft.a ./libreadline.a -lreadline -lncurses -o $(NAME)
	

all:	${NAME}

clean:
	@make -C ./libft/
	rm -f ${OBJ}

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all