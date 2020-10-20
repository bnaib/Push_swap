       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_param_len(t_format_list_el *lst)
{
	size_t len;

	len = lst->str_size;
	if (len < (size_t)lst->modifiers.accuracy)
		len = (size_t)lst->modifiers.accuracy;
	if (lst->sign || lst->modifiers.flags & FM_FLAG_PLUS
		|| lst->modifiers.flags & FM_FLAG_SPACE)
		len++;
	if (len < (size_t)lst->modifiers.width)
		len = (size_t)lst->modifiers.width;
	if (lst->modifiers.flags & FM_FLAG_OCTOTHORPE)
		len += 2;
	return (len);
}
