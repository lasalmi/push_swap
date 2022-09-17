COMMON_FILES = nodes.c stacks.c initializers.c arg_input.c error.c \
print_stacks.c utils.c dispatcher.c checks.c \
rotates.c swaps.c
COMMON_SRC_DIR = ./common/
COMMON_SRC := $(addprefix $(COMMON_SRC_DIR),$(COMMON_FILES))
CHECKER_FILES = checker_main.c checker_instructions.c
CHECKER_SRC_DIR = ./checker_src/
CHECKER_SRC := $(addprefix $(CHECKER_SRC_DIR),$(CHECKER_FILES))
PUSH_SWAP_FILES = push_swap_main.c costs.c \
instructions.c solver.c solver_utils.c solver_small.c preliminary.c \
finders.c presort.c instruction_generators.c
PUSH_SWAP_SRC_DIR = ./push_swap_src/
PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(PUSH_SWAP_FILES))
COMMON_OBJ := $(COMMON_FILES:.c=.o)
CHECKER_OBJ := $(CHECKER_FILES:.c=.o)
PW_OBJ := $(PUSH_SWAP_FILES:.c=.o)
NAME = push_swap
CHECKER = checker
# PUSH_SWAP = push_swap
LIB_NAME = ./libft/libft.a
LIB_DIR = ./libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(CHECKER)

re : fclean all

$(CHECKER) : $(CHECKER_OBJ) $(COMMON_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -o checker -L$(LIB_DIR) $(CHECKER_OBJ) $(COMMON_OBJ) -lft

$(CHECKER_OBJ) : $(CHECKER_SRC)
	gcc $(CFLAGS) -c -I. $(CHECKER_SRC)

$(COMMON_OBJ) : $(COMMON_SRC)
	gcc $(CFLAGS) -c -I. $(COMMON_SRC)

$(NAME) : $(PW_OBJ) $(COMMON_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -L$(LIB_DIR) $(PW_OBJ) $(COMMON_OBJ) -o $(NAME) -lft

$(PW_OBJ) : $(PUSH_SWAP_SRC)
	gcc $(CFLAGS) -c -I. $(PUSH_SWAP_SRC)

$(LIB_NAME) :
	make -C libft

TEST : $(NAME) main.c
	gcc -Wall -Wextra -Werror -g -Ilibft -I. -L. main.c -lftft_printf
	./a.out

clean : 
	rm -f $(CHECKER_OBJ) $(PW_OBJ) $(COMMON_OBJ)
	make clean -C libft/

fclean : clean
	rm -f ./$(CHECKER) ./$(NAME)
	make fclean -C libft/