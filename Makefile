CHECKER_SRC = main.c nodes.c
CHECKER_SRC_DIR = ./checker/
PUSH_SWAP_SRC = ./libft/
PUSH_SWAP_SRC_DIR = ./push_swap/
CHECKER_OBJ := $(CHECKER_SRC:.c=.o)
PUSH_SWAP_OBJ := $(PUSH_SWAP_OBJ:.c=.o)
CHECKER = checker
PUSH_SWAP = push_swap
LIB_NAME = libft.a
LIB_DIR = ./libft/
CC = gcc
#CFLAGS = -Wall -Wextra -Werror

all : $(CHECKER) #$(PUSH_SWAP)

re : fclean all

$(CHECKER) : $(CHECKER_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -g -L$(LIB_DIR) $(CHECKER_OBJ) -lft

$(CHECKER_OBJ) : $(CHECKER_SRC_DIR)$(CHECKER_SRC)
	gcc $(CFLAGS) -c -g -I. $(CHECKER_SRC_DIR)$(CHECKER_SRC)

#$(PUSH_SWAP) : $(PUSH_SWAP_OBJ) $(LIB_NAME)
#	gcc $(CFLAGS) -L$(LIB_DIR) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) -lft

#$(PUSH_SWAP_OBJ) : $(PUSH_SWAP_SRC_DIR)$(PUSH_SWAP_SRC)
#	gcc $(CFLAGS) -c $(PUSH_SWAP_SRC)

$(LIB_NAME) : 
	make -C libft
TEST : $(NAME) main.c
	gcc -Wall -Wextra -Werror -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	make clean -C libft/

fclean : clean
	rm -f $(CHECKER) $(PUSH_SWAP)
	make fclean -C libft/