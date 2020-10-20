       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2019.09.08 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.10.21 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

NAME = libft.a
FNAMES =\
	ft_memset~		ft_memalloc~		ft_lstnew~		ft_itoalen~\
	ft_bzero~		ft_memdel~			ft_lstdelone~	ft_isspace~\
	ft_memcpy~		ft_strnew~			ft_lstdel~		ft_strsplitwsize~\
	ft_memccpy~		ft_strdel~			ft_lstadd~		ft_strsplitwcount~\
	ft_memmove~		ft_strclr~			ft_lstiter~		ft_arrfree~\
	ft_memchr~		ft_striter~			ft_lstmap~		ft_islower~\
	ft_memcmp~		ft_striteri~						ft_isupper~\
	ft_strlen~		ft_strmap~							ft_isblank~\
	ft_strdup~		ft_strmapi~							ft_iscntrl~\
	ft_strcpy~		ft_strequ~\
	ft_strncpy~		ft_strnequ~\
	ft_strcat~		ft_strsub~\
	ft_strncat~		ft_strjoin~\
	ft_strlcat~		ft_strtrim~\
	ft_strchr~		ft_strsplit~\
	ft_strrchr~		ft_itoa~\
	ft_strstr~		ft_putchar~\
	ft_strnstr~		ft_putstr~\
	ft_strcmp~		ft_putendl~\
	ft_strncmp~		ft_putnbr~\
	ft_atoi~		ft_putchar_fd~\
	ft_isalpha~		ft_putstr_fd~\
	ft_isdigit~		ft_putendl_fd~\
	ft_isalnum~		ft_putnbr_fd~\
	ft_isascii~\
	ft_isprint~\
	ft_toupper~\
	ft_tolower~

SRC = $(subst ~,.c,$(FNAMES))
OBJ = $(subst ~,.o,$(FNAMES))

all: $(NAME)
$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC);
	@ar rc $(NAME) $(OBJ);
	@ranlib $(NAME);
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
