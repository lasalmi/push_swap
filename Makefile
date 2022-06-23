COMMON_FILES = nodes.c stacks.c initializers.c arg_input.c error.c ft_printlist.c utils.c dispatcher.c list_debug.c
COMMON_SRC_DIR = ./common/
COMMON_SRC := $(addprefix $(COMMON_SRC_DIR),$(COMMON_FILES))
CHECKER_FILES = checker_main.c
CHECKER_SRC_DIR = ./checker_src/
CHECKER_SRC := $(addprefix $(CHECKER_SRC_DIR),$(CHECKER_FILES))
PUSH_SWAP_FILES = push_swap_main.c	chunks.c sandbox.c target.c costs.c instructions.c
PUSH_SWAP_SRC_DIR = ./push_swap_src/
PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(PUSH_SWAP_FILES))
CHECKER_OBJ := $(CHECKER_FILES:.c=.o)
PUSH_SWAP_OBJ := $(PUSH_SWAP_FILES:.c=.o)
COMMON_OBJ := $(COMMON_FILES:.c=.o)
CHECKER = checker
PUSH_SWAP = push_swap
LIB_NAME = libft.a
LIB_DIR = ./libft/
CC = gcc
#CFLAGS = -Wall -Wextra -Werror

all : $(CHECKER) $(PUSH_SWAP)

re : fclean all

$(CHECKER) : $(CHECKER_OBJ) $(COMMON_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -o checker -g -L$(LIB_DIR) $(CHECKER_OBJ) $(COMMON_OBJ) -lft

$(CHECKER_OBJ) : $(CHECKER_SRC)
	gcc $(CFLAGS) -c -g -I. $(CHECKER_SRC)

$(COMMON_OBJ) : $(COMMON_SRC)
	gcc $(CFLAGS) -c -g -I. $(COMMON_SRC)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -L$(LIB_DIR) $(PUSH_SWAP_OBJ) $(COMMON_OBJ) -o $(PUSH_SWAP) -lft

$(PUSH_SWAP_OBJ) : $(PUSH_SWAP_SRC)
	gcc $(CFLAGS) -c -g -I. $(PUSH_SWAP_SRC)

$(LIB_NAME) : 
	make -C libft
TEST : $(NAME) main.c
	gcc -Wall -Wextra -Werror -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(COMMON_OBJ)
	make clean -C libft/

fclean : clean
	rm -f ./$(CHECKER) ./$(PUSH_SWAP)
	make fclean -C libft/