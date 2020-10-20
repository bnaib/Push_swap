       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2020.09.15 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.09.15 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

NAME = libio.a
FLAGS = -Wall -Wextra -Werror

HFILES =\
	io.h

CFILES		=\
	istream.c\
	get_line_from_last_read_list.c\
	get_line.c

INC_DIR = ./inc/
INC = $(addprefix $(INC_DIR), $(HFILES))

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(CFILES))

OBJ_DIR = ./obj/
OFILES = $(patsubst %.c, %.o, $(CFILES))
OBJ = $(addprefix $(OBJ_DIR), $(OFILES))


.PHONY: all clean fclean re

all: checkDir $(NAME)

submodules_update:
	git submodule update;

checkDir:
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
