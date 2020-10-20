       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.05 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

size_t			ft_printf_get_star(
					const char *format_n,
					long long int *result,
					va_list *p_args,
					va_list *p_args_root)
{
	size_t			i;
	unsigned int	buf;

	i = 0;
	while (format_n[i] >= '0' && format_n[i] <= '9')
		i++;
	if (i == 0 || format_n[i] != '$')
	{
		*result = va_arg(*p_args, long long);
		return (format_n[i] == '$');
	}
	buf = ft_printf_get_fm_uint(format_n, i);
	*result = ft_printf_get_n_arg(p_args_root, (int)buf);
	return (++i);
}
