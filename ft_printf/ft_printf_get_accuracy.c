       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.02 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static void	ft_printf_get_accuracy_fix(
				long long int buf,
				t_format_list_el *fm_list)
{
	if ((int)buf >= 0)
	{
		fm_list->modifiers.accuracy = (int)buf;
		fm_list->modifiers.flags |= FM_FLAG_ACCURACY;
	}
	else
	{
		fm_list->modifiers.accuracy = 0;
		fm_list->modifiers.flags &= ~(int)FM_FLAG_ACCURACY;
	}
}

size_t		ft_printf_get_accuracy(
				const char *format_n,
				va_list *p_args,
				va_list *p_args_root,
				t_format_list_el *fm_list)
{
	size_t			i;
	long long		buf;

	if (format_n[0] != '.')
		return (0);
	if (format_n[1] == '*')
	{
		i = ft_printf_get_star(&(format_n[2]), &buf, p_args, p_args_root);
		ft_printf_get_accuracy_fix(buf, fm_list);
		return (i + 2);
	}
	i = 1;
	while (format_n[i] >= '0' && format_n[i] <= '9')
		i++;
	fm_list->modifiers.flags |= FM_FLAG_ACCURACY;
	fm_list->modifiers.accuracy = (int)ft_printf_get_fm_uint(&(format_n[1]),
		i - 1);
	return (i);
}
