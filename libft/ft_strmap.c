       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		ss;
	size_t		i;
	char		*str;

	if (!s || !f)
		return (NULL);
	ss = ft_strlen(s);
	str = malloc(sizeof(*str) * (ss + 1));
	if (str)
	{
		i = 0;
		while (i < ss)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[ss] = 0;
	}
	return (str);
}
