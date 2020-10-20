       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.02 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

size_t		ft_printf_get_flags(
				const char *format_n,
				t_format_list_el *fm_list)
{
	size_t		i;

	i = 0;
	while (1)
	{
		if (format_n[i] == '-')
			fm_list->modifiers.flags |= FM_FLAG_MINUS;
		else if (format_n[i] == '+')
			fm_list->modifiers.flags |= FM_FLAG_PLUS;
		else if (format_n[i] == '0')
			fm_list->modifiers.flags |= FM_FLAG_0;
		else if (format_n[i] == '#')
			fm_list->modifiers.flags |= FM_FLAG_OCTOTHORPE;
		else if (format_n[i] == ' ')
			fm_list->modifiers.flags |= FM_FLAG_SPACE;
		else
			return (i);
		i++;
	}
}
