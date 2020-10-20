       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.02 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

size_t		ft_printf_get_width(
				const char *format_n,
				va_list *p_args,
				va_list *p_args_root,
				t_format_list_el *fm_list)
{
	size_t			i;
	long long		buf;

	if (format_n[0] == '*')
	{
		i = ft_printf_get_star(&(format_n[1]), &buf, p_args, p_args_root);
		fm_list->modifiers.width = (int)buf;
		if (fm_list->modifiers.width < 0)
		{
			fm_list->modifiers.flags |= FM_FLAG_MINUS;
			fm_list->modifiers.width *= -1;
		}
		fm_list->modifiers.flags |= FM_FLAG_WIDTH;
		return (++i);
	}
	i = 0;
	while (format_n[i] >= '0' && format_n[i] <= '9')
		i++;
	if (i == 0 || format_n[i] == '$')
		return (0);
	fm_list->modifiers.width = (int)ft_printf_get_fm_uint(format_n, i);
	fm_list->modifiers.flags |= FM_FLAG_WIDTH;
	return (i);
}
