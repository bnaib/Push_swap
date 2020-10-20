       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.05 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void				ft_printf_get_mult_arg(
						va_list *p_args_root,
						t_format_list_el *fm_list)
{
	va_list			args;
	int				i;

	va_copy(args, *p_args_root);
	i = 0;
	while (++i != fm_list->modifiers.dollar)
		va_arg(args, long long int);
	if (fm_list->modifiers.type[0] == 'f' || fm_list->modifiers.type[0] == 'F')
	{
		if (fm_list->modifiers.prefix & FM_PREFIX_BIG_L)
			fm_list->param.llf.val = va_arg(args, long double);
		else
			fm_list->param.llf.val = (long double)va_arg(args, double);
	}
	else
		fm_list->param.lld = va_arg(args, long long int);
	va_end(args);
}

long long int		ft_printf_get_n_arg(va_list *p_args_root, int n)
{
	long long int	result;
	va_list			args;
	int				i;

	va_copy(args, *p_args_root);
	i = 0;
	while (++i != n)
		va_arg(args, long long int);
	result = va_arg(args, long long int);
	va_end(args);
	return (result);
}
