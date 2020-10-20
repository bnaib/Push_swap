       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.03 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static void	ft_printf_get_prefix_double(
				const char *format_n,
				t_format_list_el *fm_list,
				char c,
				size_t *i)
{
	if (format_n[*i + 1] == c)
	{
		fm_list->modifiers.prefix |= (c == 'l') ? FM_PREFIX_LL : FM_PREFIX_HH;
		(*i)++;
	}
	else
		fm_list->modifiers.prefix |= (c == 'l') ? FM_PREFIX_L : FM_PREFIX_H;
}

size_t		ft_printf_get_prefix(
				const char *format_n,
				t_format_list_el *fm_list)
{
	size_t		i;

	i = 0;
	while (1)
	{
		if (format_n[i] == 'l')
			ft_printf_get_prefix_double(format_n, fm_list, 'l', &i);
		else if (format_n[i] == 'h')
			ft_printf_get_prefix_double(format_n, fm_list, 'h', &i);
		else if (format_n[i] == 'j')
			fm_list->modifiers.prefix |= FM_PREFIX_J;
		else if (format_n[i] == 'z')
			fm_list->modifiers.prefix |= FM_PREFIX_Z;
		else if (format_n[i] == 't')
			fm_list->modifiers.prefix |= FM_PREFIX_T;
		else if (format_n[i] == 'L')
			fm_list->modifiers.prefix |= FM_PREFIX_BIG_L;
		else
			return (i);
		i++;
	}
}
