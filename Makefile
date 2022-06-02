CHECKER_SRC = 
CHECKER_SRC_DIR = ./checker/
PUSH_SWAP_SRC = ./libft/
PUSH_SWAP_SRC_DIR = ./push_swap/
CHECKER_OBJ := $(CHECKER_SRC:.c=.o)
PUSH_SWAP_OBJ := $(PUSH_SWAP_OBJ:.c=.o)
CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(CHECKER) $(PUSH_SWAP)

re : fclean all

$(CHECKER) : $(CHECKER_OBJ)
	gcc $(CFLAGS) $(CHECKER_OBJ) -o $(CHECKER) -lft

$(CHECKER_OBJ) : $(CHECKER_SRC_DIR)$(CHECKER_SRC)
	gcc $(CFLAGS) -c $(SOURCES)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJ)
	gcc $(CFLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) -lft

$(PUSH_SWAP_OBJ) : $(PUSH_SWAP_SRC_DIR)$(PUSH_SWAP_SRC)
	gcc $(CFLAGS) -c $(PUSH_SWAP_SRC)

TEST : $(NAME) main.c
	gcc -Wall -Wextra -Werror -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	make clean -C libft/

fclean : clean
	rm -f $(CHECKER) $(PUSH_SWAP)
	make fclean -C libft/