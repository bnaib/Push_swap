       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.04 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*st;
	unsigned char	*sf;

	uc = (unsigned char)c;
	st = (unsigned char *)dst;
	sf = (unsigned char *)src;
	while (n)
	{
		*st = *sf;
		if (*sf == uc)
			return (st + 1);
		st++;
		sf++;
		n--;
	}
	return (NULL);
}
