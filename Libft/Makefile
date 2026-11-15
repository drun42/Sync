
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAIN = test_main.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#  ($<) the first dependency / ($@) the target file / (%) same behaviour as * in bash

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f  $(OBJ)

fclean: clean
	rm -f $(NAME)

re: $(NAME)
	make fclean
	make all

test: $(NAME) $(MAIN)
	make re
	$(CC) $(CFLAGS) $(NAME) $(MAIN)
	./a.out

comp: $(SRC)
	$(CC) $(CFLAGS) $(SRC)


