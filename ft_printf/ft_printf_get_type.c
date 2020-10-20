       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.05 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static char	ft_printf_get_type_check_format_n(const char *format_n)
{
	if (*format_n != '%' && *format_n != 'c' && *format_n != 'C'
		&& *format_n != 'd' && *format_n != 'i' && *format_n != 'o'
		&& *format_n != 'u' && *format_n != 'x' && *format_n != 'X'
		&& *format_n != 'e' && *format_n != 'E' && *format_n != 'f'
		&& *format_n != 'F' && *format_n != 'g' && *format_n != 'G'
		&& *format_n != 'a' && *format_n != 'A' && *format_n != 'n'
		&& *format_n != 'p' && *format_n != 's' && *format_n != 'S'
		&& *format_n != 'b' && *format_n != 'r' && *format_n != 'U'
		&& *format_n != 'D' && *format_n != 'O' && *format_n != 'C'
		&& *format_n != 'S')
		return (1);
	return (0);
}

size_t		ft_printf_get_type(
				const char *format_n,
				va_list *p_args,
				va_list *p_args_root,
				t_format_list_el *fm_list)
{
	if (ft_printf_get_type_check_format_n(format_n))
		return (0);
	if (*format_n == 'D' || *format_n == 'O' || *format_n == 'C'
		|| *format_n == 'S')
	{
		fm_list->modifiers.prefix = FM_PREFIX_L;
		fm_list->modifiers.type[0] = *format_n + 32;
	}
	else
		fm_list->modifiers.type[0] = *format_n;
	if (*format_n != '%')
	{
		if (fm_list->modifiers.flags & FM_FLAG_DOLLAR)
			ft_printf_get_mult_arg(p_args_root, fm_list);
		else if (*format_n == 'f' || *format_n == 'F')
		{
			if (fm_list->modifiers.prefix & FM_PREFIX_BIG_L)
				fm_list->param.llf.val = va_arg(*p_args, long double);
			else
				fm_list->param.llf.val = (long double)va_arg(*p_args, double);
		}
		else
			fm_list->param.lld = va_arg(*p_args, long long int);
	}
	return (1);
}
