       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.11 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "libft.h"

int		ft_strsplitwcount(char const *s, char c)
{
	int		i;
	int		ws;
	int		r;

	i = 0;
	r = 0;
	while (s[i])
	{
		ws = ft_strsplitwsize(s + i, c);
		if (ws)
		{
			r++;
			i += ws;
		}
		else
			i++;
	}
	return (r);
}
