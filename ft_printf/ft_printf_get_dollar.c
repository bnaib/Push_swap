       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.05 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

size_t			ft_printf_get_dollar(
					const char *format_n,
					t_format_list_el *fm_list)
{
	size_t			i;

	i = 0;
	while (format_n[i] >= '0' && format_n[i] <= '9')
		i++;
	if (i == 0 || format_n[i] != '$')
		return (0);
	fm_list->modifiers.dollar = (int)ft_printf_get_fm_uint(format_n, i);
	fm_list->modifiers.flags |= FM_FLAG_DOLLAR;
	return (++i);
}
