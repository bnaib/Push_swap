       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.10 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dl;
	size_t		sl;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (!size)
		return (sl);
	if (dl >= size)
		return (size + sl);
	if (dl + sl < size)
	{
		ft_strncpy(dst + dl, src, sl);
		*(dst + dl + sl) = 0;
	}
	else
	{
		ft_strncpy(dst + dl, src, size - dl - 1);
		*(dst + size - 1) = 0;
	}
	return (dl + sl);
}
