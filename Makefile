       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2020.09.15 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.10.21 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

CHECKER_NAME			= checker
CHECKER_DIR				= checker
CHECKER_FLAGS			= -Wall -Wextra -Werror

PUSH_SWAP_NAME			= push_swap
PUSH_SWAP_DIR			= push_swap
PUSH_SWAP_FLAGS			= -g -Wall -Wextra -Werror

CHECKER_HF				=\
	checker.h

CHECKER_CF				=\
	checker.c\
	exit_program.c\
	stack_list_content.c\
	command_list_content.c\
	load_default.c\
	check_sort.c\
	load_params.c\
	check_space_str.c\
	check_atoi.c\
	swap.c\
	push.c\
	rotate.c\
	reverse_rotate.c\
	load_commands.c\
	do_commands.c\
	print_usage.c\
	print_state.c\
	print_state_numbers.c\
	print_state_lines.c\
	set_index.c\
	find_in_list.c

CHECKER_LIB_INC			=\
	-I ./clib_classlist/inc\
	-I ./clib_io/inc\
	-I ./ft_printf\
	-I ./libft

CHECKER_LIB_BIN			=\
	-L ./clib_classlist -lclasslist\
	-L ./clib_io -lio\
	-L ./ft_printf -lftprintf\
	-L ./libft -lft

PUSH_SWAP_HF				=\
	push_swap.h

PUSH_SWAP_CF				=\
	push_swap.c\
	stack_list_content.c\
	command_list_content.c\
	load_default.c\
	exit_program.c\
	check_space_str.c\
	check_atoi.c\
	load_params.c\
	set_index.c\
	norm.c\
	swap.c\
	push.c\
	rotate.c\
	reverse_rotate.c\
	add_command.c\
	solve.c\
	solve_a.c\
	solve_b.c\
	print_commands.c\
	direction.c\
	find_a_elem.c\
	print_usage.c\
	print_state.c\
	print_state_numbers.c\
	print_state_lines.c\
	find_in_list.c

PUSH_SWAP_LIB_INC			=\
	-I ./clib_classlist/inc\
	-I ./ft_printf\
	-I ./libft

PUSH_SWAP_LIB_BIN			=\
	-L ./clib_classlist -lclasslist\
	-L ./ft_printf -lftprintf\
	-L ./libft -lft


INC_DIR					= ./inc
SRC_DIR					= ./src
OBJ_DIR					= ./obj

CHECKER_INC_DIR			= $(INC_DIR)/$(CHECKER_DIR)/
CHECKER_INC				= $(addprefix $(CHECKER_INC_DIR), $(CHECKER_HF))

PUSH_SWAP_INC_DIR		= $(INC_DIR)/$(PUSH_SWAP_DIR)/
PUSH_SWAP_INC			= $(addprefix $(PUSH_SWAP_INC_DIR), $(PUSH_SWAP_HF))

CHECKER_SRC_DIR			= $(SRC_DIR)/$(CHECKER_DIR)/
CHECKER_SRC				= $(addprefix $(CHECKER_SRC_DIR), $(CHECKER_CF))

PUSH_SWAP_SRC_DIR		= $(SRC_DIR)/$(PUSH_SWAP_DIR)/
PUSH_SWAP_SRC			= $(addprefix $(PUSH_SWAP_SRC_DIR), $(PUSH_SWAP_CF))

CHECKER_OBJ_DIR			= $(OBJ_DIR)/$(CHECKER_DIR)/
CHECKER_OF				= $(patsubst %.c, %.o, $(CHECKER_CF))
CHECKER_OBJ				= $(addprefix $(CHECKER_OBJ_DIR), $(CHECKER_OF))

PUSH_SWAP_OBJ_DIR		= $(OBJ_DIR)/$(PUSH_SWAP_DIR)/
PUSH_SWAP_OF			= $(patsubst %.c, %.o, $(PUSH_SWAP_CF))
PUSH_SWAP_OBJ			= $(addprefix $(PUSH_SWAP_OBJ_DIR), $(PUSH_SWAP_OF))

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ_DIR) $(CHECKER_OBJ)
	make -C ./clib_classlist;
	make -C ./clib_io;
	make -C ./ft_printf;
	make -C ./libft;
	gcc\
		$(CHECKER_FLAGS)\
		-I $(CHECKER_INC_DIR)\
		$(CHECKER_LIB_INC)\
		-o $(CHECKER_NAME)\
		$(CHECKER_OBJ)\
		$(CHECKER_LIB_BIN);

$(CHECKER_OBJ_DIR):
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	if [ ! -d $(CHECKER_OBJ_DIR) ]; then mkdir $(CHECKER_OBJ_DIR); fi

$(CHECKER_OBJ_DIR)%.o: $(CHECKER_SRC_DIR)%.c $(CHECKER_INC)
	gcc\
		$(CHECKER_FLAGS)\
		-I $(CHECKER_INC_DIR)\
		$(CHECKER_LIB_INC)\
		-o $@ -c $<;

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ_DIR) $(PUSH_SWAP_OBJ)
	make -C ./clib_classlist;
	make -C ./clib_io;
	make -C ./ft_printf;
	make -C ./libft;
	gcc\
		$(PUSH_SWAP_FLAGS)\
		-I $(PUSH_SWAP_INC_DIR)\
		$(PUSH_SWAP_LIB_INC)\
		-o $(PUSH_SWAP_NAME)\
		$(PUSH_SWAP_OBJ)\
		$(PUSH_SWAP_LIB_BIN);

$(PUSH_SWAP_OBJ_DIR):
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	if [ ! -d $(PUSH_SWAP_OBJ_DIR) ]; then mkdir $(PUSH_SWAP_OBJ_DIR); fi

$(PUSH_SWAP_OBJ_DIR)%.o: $(PUSH_SWAP_SRC_DIR)%.c $(PUSH_SWAP_INC)
	gcc\
		$(PUSH_SWAP_FLAGS)\
		-I $(PUSH_SWAP_INC_DIR)\
		$(PUSH_SWAP_LIB_INC)\
		-o $@ -c $<;

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME)

re: fclean all

cleanlibs:
	make -C ./clib_classlist clean;
	make -C ./clib_io clean;
	make -C ./ft_printf clean;
	make -C ./libft clean;

fcleanlibs:
	make -C ./clib_classlist fclean;
	make -C ./clib_io fclean;
	make -C ./ft_printf fclean;
	make -C ./libft fclean;

relibs:
	make -C ./clib_classlist re;
	make -C ./clib_io re;
	make -C ./ft_printf re;
	make -C ./libft re;
