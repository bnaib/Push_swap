       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.06 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_get_fm_uint(const char *format_n, size_t i0)
{
	size_t			i1;
	unsigned int	buf;

	i1 = (i0 > 32) ? (i0 - 32 - 1) : -1;
	buf = 0;
	while (format_n[++i1] >= '0' && format_n[i1] <= '9')
		buf = buf * 10 + (format_n[i1] - '0');
	return (buf);
}
