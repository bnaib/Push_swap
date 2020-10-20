       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2020.01.02 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.10.21 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FNAMES =\
	ft_printf~		ft_printf_get_type~			ft_printf_get_n_arg~\
	ft_work_list~	ft_printf_get_flags~		ft_printf_get_fm_uint~\
					ft_printf_get_dollar~		ft_printf_get_star~\
	ft_fm_int~		ft_printf_get_width~		calculate_wstrlen~\
	ft_fm_uint~		ft_printf_get_accuracy~		ft_ltoa~\
	ft_fm_percent~	ft_printf_get_prefix~		ft_param_len~\
												ft_check_flags~\
	ft_fill_str~	ft_printf_set_str~			ft_check_str~\
												convert_utf32_to_utf8~\
					ft_advlongd_str~			ft_printf_check_color~\
					ft_advlongd_main~			ft_printf_exit~\
					ft_advlongd_math~\
					ft_advlongd_infnan~\
					ft_advlongd_round~


SRC = $(subst ~,.c,$(FNAMES))
OBJ = $(subst ~,.o,$(FNAMES))

all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ);
	@ranlib $(NAME);
$(OBJ): %.o: %.c
	@gcc $(FLAGS) -o $@ -c $<;
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
