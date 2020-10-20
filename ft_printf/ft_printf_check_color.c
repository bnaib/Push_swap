       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.11 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static char			ft_printf_check_color_text(
						char *str,
						size_t *i,
						char *str_find,
						size_t size)
{
	int		a[2];

	a[0] = 0;
	a[1] = i[0] - size;
	while (str_find[a[0]] != '\0' && str_find[a[0]] == str[a[1]++])
		a[0]++;
	if (str_find[a[0]] != '\0')
		return (0);
	write(1, str, i[0] - size);
	i[0] = 0;
	return (1);
}

void				ft_printf_check_color(
						char *str,
						char c,
						size_t *i)
{
	str[i[0]++] = c;
	if (c != '}')
		return ;
	if (ft_printf_check_color_text(str, i, "{eoc}", 5))
		write(1, "\33[0m", 4);
	else if (ft_printf_check_color_text(str, i, "{red}", 5))
		write(1, "\33[0;31m", 7);
	else if (ft_printf_check_color_text(str, i, "{green}", 7))
		write(1, "\33[0;32m", 7);
	else if (ft_printf_check_color_text(str, i, "{yellow}", 8))
		write(1, "\33[0;33m", 7);
	else if (ft_printf_check_color_text(str, i, "{blue}", 6))
		write(1, "\33[0;34m", 7);
	else if (ft_printf_check_color_text(str, i, "{magenta}", 9))
		write(1, "\33[0;35m", 7);
	else if (ft_printf_check_color_text(str, i, "{cyan}", 6))
		write(1, "\33[0;36m", 7);
}
